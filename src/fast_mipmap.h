#pragma once

#include <cstdint>
#include <stdlib.h>
#include <memory>

typedef uint8_t u8;

class ImageU8
{
public:
	ImageU8(int width, int height) : m_width(width), m_height(height) {
		m_pixels = (u8*)malloc(width * height);
	}

	~ImageU8() {
		free(m_pixels);
	}

	int width() const { return m_width; }
	int height() const { return m_height; }

	u8 pixelAt(int x, int y) const { return m_pixels[y * m_width + x]; }

	u8* mutablePixels() { return m_pixels;}
	const u8* pixels() const { return m_pixels; }

private:
	int m_width;
	int m_height;
	u8* m_pixels;
};

std::shared_ptr<ImageU8> reduceImage(const uint8_t* data, int width, int height);
