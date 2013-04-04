// Manage a text file with a black-white image

#include <fstream>

class Complex;

class InputImage {
public:
    InputImage(const char* fileName);
    int GetWidth() const;
    int GetHeight() const;
    Complex* GetImageData() const;
    void SaveImageData(const char* newFileName, Complex* d, int w, int h);
private:
    int w;          // width of image
    int h;          // height of image
    Complex* data;  // The data
};
