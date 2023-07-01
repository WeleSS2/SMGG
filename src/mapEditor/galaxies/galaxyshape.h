#pragma once
#include <iostream>



class GalaxyShape
{
public:
    // Load bmp map from a file
    unsigned char* loadBMP(const char* file, int width, int height);

    // Load density map from a file
    void loadDensityMapFromFile(const char* file);



    explicit GalaxyShape();

private:
};
