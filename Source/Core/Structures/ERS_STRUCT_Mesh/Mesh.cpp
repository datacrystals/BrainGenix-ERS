//======================================================================//
// This file is part of the BrainGenix-ERS Environment Rendering System //
//======================================================================//

#include "Mesh.h"
#include "../ERS_STRUCT_Vertex/Vertex.h"


void ERS_STRUCT_Mesh::SetupMesh() {

    // Initialize Buffers/Arrays
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    // Bind To Vert Array
    glBindVertexArray(VAO);
    
    // Populate Vertex Buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, Vertices.size() * sizeof(ERS_STRUCT_Vertex), &Vertices[0], GL_STATIC_DRAW);

    // Populate Element Buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, Indices.size() * sizeof(unsigned int), &Indices[0], GL_STATIC_DRAW);


    // Set Vertex Attribute Pointers
    
    // Position Data
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ERS_STRUCT_Vertex), (void*)0);

    // Normals Data
    glEnableVertexAttribArray(1);	
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(ERS_STRUCT_Vertex), (void*)offsetof(ERS_STRUCT_Vertex, Normal));

    // Texture Coordinate Data
    glEnableVertexAttribArray(2);	
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(ERS_STRUCT_Vertex), (void*)offsetof(ERS_STRUCT_Vertex, TexCoords));

    // Vertex Tangent
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(ERS_STRUCT_Vertex), (void*)offsetof(ERS_STRUCT_Vertex, Tangent));

    // Vertex Bitangent
    glEnableVertexAttribArray(4);
    glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(ERS_STRUCT_Vertex), (void*)offsetof(ERS_STRUCT_Vertex, Bitangent));

    // IDs
    glEnableVertexAttribArray(5);
    glVertexAttribIPointer(5, 4, GL_INT, sizeof(ERS_STRUCT_Vertex), (void*)offsetof(ERS_STRUCT_Vertex, BoneIDs));

    // Weights
    glEnableVertexAttribArray(6);
    glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(ERS_STRUCT_Vertex), (void*)offsetof(ERS_STRUCT_Vertex, Weights));

    // Unbind From Vert Array
    glBindVertexArray(0);


    // Set NumberIndices
    NumberIndices = Indices.size();



}


void ERS_STRUCT_Mesh::GenerateUVSphere(float radius, int sectorCount, int stackCount, std::vector<ERS_STRUCT_Vertex>& vertices, std::vector<unsigned int>& indices) {
    float x, y, z, xy; 
    float nx, ny, nz, lengthInv = 1.0f / radius; 
    float s, t;

    float sectorStep = 2 * M_PI / sectorCount;
    float stackStep = M_PI / stackCount;
    float sectorAngle, stackAngle;

    for (int i = 0; i <= stackCount; ++i) {
        stackAngle = M_PI / 2 - i * stackStep; 
        xy = radius * cosf(stackAngle); 
        z = radius * sinf(stackAngle); 

        for (int j = 0; j <= sectorCount; ++j) {
            sectorAngle = j * sectorStep; 

            x = xy * cosf(sectorAngle); 
            y = xy * sinf(sectorAngle); 
            ERS_STRUCT_Vertex vertex;
            vertex.Position = glm::vec3(x, y, z);
            vertex.Normal = glm::vec3(x * lengthInv, y * lengthInv, z * lengthInv);
            vertex.TexCoords = glm::vec2((float)j / sectorCount, (float)i / stackCount);
            vertices.push_back(vertex);

            if (i != 0 && j != 0) {
                int cur = i * (sectorCount + 1) + j;
                int prev = (i - 1) * (sectorCount + 1) + j;

                indices.push_back(prev);
                indices.push_back(cur);
                indices.push_back(cur - 1);

                indices.push_back(prev - 1);
                indices.push_back(prev);
                indices.push_back(cur - 1);
            }
        }
    }
}

void ERS_STRUCT_Mesh::ResetTexture(const char* Name, int Offset, unsigned int ShaderProgram, unsigned int TextureID) {

    glUniform1i(glGetUniformLocation(ShaderProgram, Name), Offset);
    glActiveTexture(GL_TEXTURE0 + Offset);
    glBindTexture(GL_TEXTURE_2D, TextureID);

}

void ERS_STRUCT_Mesh::UpdateTransparencyStatus() {

    // Check Color Channels
    HasTransparency_ = false;
    for (unsigned long i = 0; i < TextureColorChannels_.size(); i++) {
        if (TextureColorChannels_[i] == 4) {
            HasTransparency_ = true;
        }
    }

}