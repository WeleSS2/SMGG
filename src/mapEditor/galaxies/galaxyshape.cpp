#include "galaxyshape.h"

GalaxyShape::GalaxyShape()
{

}
/*
unsigned char* LoadBMP( const char* FileName, int* OutWidth, int* OutHeight )
{
    sBMPHeader Header;

    std::ifstream File( FileName, std::ifstream::binary );

    File.read( (char*)&Header, sizeof( Header ) );

    *OutWidth  = Header.biWidth;
    *OutHeight = Header.biHeight;

    const size_t DataSize = 3 * Header.biWidth * Header.biHeight;

    unsigned char* Img = new unsigned char[ DataSize ];

    File.read( (char*)Img, DataSize );

    return Img;
}

void loadDensityMapFromFile( const char* FileName )
{
    std::cout << "Loading density map " << FileName << std::endl;

    int W, H;
    unsigned char* Data = LoadBMP( FileName, &W, &H );

    std::cout << "Loaded ( " << W << " x " << H << " ) " << std::endl;

    if ( W != kImageSize || H != kImageSize )
    {
        std::cout << "ERROR: density map should be " << kImageSize << " x " << kImageSize << std::endl;

        exit( 255 );
    }

    g_DensityMap = new float[ W * H ];

    for ( int y = 0; y != H; y++ )
    {
        for ( int x = 0; x != W; x++ )
        {
            g_DensityMap[ x + y * W ] = float( Data[ 3 * (x + y * W) ] ) / 255.0f;
        }
    }

    delete[]( Data );
}*/

