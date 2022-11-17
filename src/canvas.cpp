/*!
 * Canvas class implementation.
 * @file canvas.cpp
 */

#include "canvas.h"

namespace life {

  // TODO: Adicione o resto da implementação dos métodos aqui.

  //=== Members
  /// Clear the canvas with black color.
  void Canvas::clear(const Color & color){
    for(auto i{0u}; i<m_pixels.size(); i+=4){
	  	m_pixels[i] = color.channels[Color::R];
      m_pixels[i+1] = color.channels[Color::G];
      m_pixels[i+2] = color.channels[Color::B];
      m_pixels[i+3] = 255;
    }
  }
  /// Set the color of a pixel on the canvas.
  void Canvas::pixel(coord_t x, coord_t y, const Color& color){
    auto pos = y*m_width*4 + x*m_block_size*4;

    m_pixels[pos] = color.channels[Color::R];
    m_pixels[pos+1] = color.channels[Color::G];
    m_pixels[pos+2] = color.channels[Color::B];
    m_pixels[pos+3] = 255; 


/*  //lógica de um 5 x 20 para representar um pixel
    //int count=0;
  for(short i{0}; i<m_block_size; i++){
    for(short j{0}; j<m_block_size; j++, pos+=4){
      m_pixels[pos] = color.channels[Color::R];
      m_pixels[pos+1] = color.channels[Color::G];
      m_pixels[pos+2] = color.channels[Color::B];
      m_pixels[pos+3] = 255;  
    }
    pos = (y+i)*m_width*4 + x*m_block_size*4;
  }
    //desce uma linha inteira e faz denovo */
    
  }
  /// Get the pixel color from the canvas.
  Color Canvas::pixel(coord_t x, coord_t y) const{
    Color color;
    //auto pos = y*m_width*m_block_size + x*m_block_size;
		auto pos = y*m_width*4 + x*4;

    color.channels[Color::R] = m_pixels[pos+1];
    color.channels[Color::G] = m_pixels[pos+2];
    color.channels[Color::B] = m_pixels[pos+3];
    
    return color;
  }

}  // namespace life

//================================[ canvas.cpp ]================================//
