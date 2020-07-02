#pragma once

struct BlockInfo
{
    int uv_indices[6]; // 顺序按 CubeSide
    int OutlineHeight;
    //std::string textures[6]; // space or empty use pre index texture
};

