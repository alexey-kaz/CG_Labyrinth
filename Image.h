#ifndef MAIN_IMAGE_H
#define MAIN_IMAGE_H

#include <string>

constexpr int tileSize = 32;

struct Pixel
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};

constexpr Pixel backgroundColor{0, 0, 0, 0};

static Pixel BlendPixel(Pixel oldPixel, Pixel newPixel)
{
    newPixel.r = newPixel.a / 255.0 * (newPixel.r - oldPixel.r) + oldPixel.r;
    newPixel.g = newPixel.a / 255.0 * (newPixel.g - oldPixel.g) + oldPixel.g;
    newPixel.b = newPixel.a / 255.0 * (newPixel.b - oldPixel.b) + oldPixel.b;
    newPixel.a = 255;

    return newPixel;
}

struct Image
{
    explicit Image(const std::string &a_path);
    Image(int a_width, int a_height, int a_channels);

    int Save(const std::string &a_path);

    int Width()    const { return width; }
    int Height()   const { return height; }
    int Channels() const { return channels; }
    size_t Size()  const { return size; }
    Pixel* Data()        { return  data; }

    Pixel GetPixel(int x, int y) { return data[width * y + x];}
    void  PutPixel(int x, int y, const Pixel &pix) { data[width* y + x] = pix; }

    ~Image();

private:
    int width = -1;
    int height = -1;
    int channels = 4;
    size_t size = 0;
    Pixel *data = nullptr;
    bool self_allocated = false;
};



#endif //MAIN_IMAGE_H
