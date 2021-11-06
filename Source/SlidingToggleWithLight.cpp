/*
  ==============================================================================

    SlidingToggleWithLight.cpp
    Created: 5 Nov 2021 9:32:44pm
    Author:  Mac Ens

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SlidingToggleWithLight.h"

//==============================================================================
SlidingToggleWithLight::SlidingToggleWithLight()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
}

SlidingToggleWithLight::~SlidingToggleWithLight()
{
	setLookAndFeel(nullptr);
}

void SlidingToggleWithLight::paint (juce::Graphics& g)
{
//	g.setColour(juce::Colours::green);
//	g.drawRect(getLocalBounds());
	
	getLookAndFeel().drawToggleButton(g, *this, false, false);
}// paint()

void SlidingToggleWithLight::resized()
{

}// resized()
