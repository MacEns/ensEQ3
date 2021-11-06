/*
  ==============================================================================

    SlidingToggleLNF.cpp
    Created: 5 Nov 2021 9:39:36pm
    Author:  Mac Ens

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SlidingToggleLNF.h"

//==============================================================================
SlidingToggleLNF::SlidingToggleLNF()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
	toggleOnImage = juce::ImageCache::getFromMemory(BinaryData::toggle3on_png, BinaryData::toggle3on_pngSize);
	toggleOffImage = juce::ImageCache::getFromMemory(BinaryData::toggle3off_png, BinaryData::toggle3off_pngSize);
	lightOnImage = juce::ImageCache::getFromMemory(BinaryData::light1on_png, BinaryData::light1on_pngSize);
	lightOffImage = juce::ImageCache::getFromMemory(BinaryData::light1off_png, BinaryData::light1off_pngSize);
}

SlidingToggleLNF::~SlidingToggleLNF()
{
}

void SlidingToggleLNF::drawToggleButton(juce::Graphics& g,
							  juce::ToggleButton& toggle,
							  bool shouldDrawButtonAsHighlighted,
							  bool shouldDrawButtonAsDown)
{
	using namespace juce;

	//printf("Begin drawToggleButton()\n");
	if (lightOnImage.isValid())
	{
		auto bounds = toggle.getLocalBounds();
		auto toggleState = toggle.getToggleState();
		
		auto x = bounds.getX();
		auto y = bounds.getY();
		auto w = bounds.getWidth();
		auto h = bounds.getHeight();
		const float centerX = x + w * 0.5f;
		const float centerY = y + h * 0.5f;
		
		
		Image lightImage = toggleState ? lightOffImage : lightOnImage;
		Image toggleImage = toggleState ? toggleOffImage : toggleOnImage;
		
		lightImage = lightImage.rescaled(50, 50);
		
		g.drawImageAt(toggleImage, w * 0.85 - toggleImage.getWidth(), centerY - toggleImage.getHeight() * 0.5);
		g.drawImageAt(lightImage, w * 0.22 - lightImage.getWidth() * 0.5, centerY - lightImage.getHeight() * 0.5);
	}
	
	else{
		printf("Light image is invalid.\n");
	}
	
}// drawToggleButton()
