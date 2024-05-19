#pragma once

#include <iostream>
#include <string>


struct Image
{
    virtual void draw() = 0;
};

struct Bitmap : Image
{
    Bitmap(const std::string& filename) : m_filename(filename)
    {
        std::cout << "Loading image from " << m_filename << std::endl;
    }

    virtual void draw() override
    {
        std::cout << "Drawing image " << m_filename << std::endl;
    }

    std::string m_filename;
};


struct LazyBitmap : Image
{
    LazyBitmap(const std::string& filename)
    : m_filename(filename)
    {
        
    }

    ~LazyBitmap()
    {
        delete bmp;
    }

    void draw() override
    {
        if (!bmp)
        {
            bmp = new Bitmap(m_filename);
        }
        bmp->draw();
    }

private:
    Bitmap * bmp{ nullptr };
    std::string m_filename;
};
