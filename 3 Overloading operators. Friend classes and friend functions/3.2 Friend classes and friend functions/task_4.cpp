class ColorRGB {
public:
	ColorRGB() = default;
	ColorRGB(unsigned char r, unsigned char g, unsigned char b) : m_r{r}, m_g{g}, m_b{b} {}

    unsigned get_color() { 
		return m_r + m_g*256 + m_b*65536; 
	}

	friend ColorRGB operator+(const ColorRGB& first, const ColorRGB& second);

private:
	unsigned char m_r{0}, m_g{0}, m_b{0};
};

ColorRGB operator+(const ColorRGB& first, const ColorRGB& second) {
	return ColorRGB(first.m_r + second.m_r > 255 ? 255 : first.m_r + second.m_r, 
		            first.m_g + second.m_g > 255 ? 255 : first.m_g + second.m_g, 
					first.m_b + second.m_b > 255 ? 255 : first.m_b + second.m_b
	);
}
