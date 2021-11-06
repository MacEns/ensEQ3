/*
  ==============================================================================

    SlidingToggleLNF.h
    Created: 5 Nov 2021 9:39:36pm
    Author:  Mac Ens

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class SlidingToggleLNF  : public juce::LookAndFeel_V4
{
public:
    SlidingToggleLNF();
    ~SlidingToggleLNF() override;

	void paint (juce::Graphics&) ;
	void resized() ;
	
	virtual void drawToggleButton(juce::Graphics& g,
								  juce::ToggleButton& toggle,
								  bool shouldDrawButtonAsHighlighted,
								  bool shouldDrawButtonAsDown) override;
	
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SlidingToggleLNF)
	juce::Image toggleOnImage;
	juce::Image toggleOffImage;
	juce::Image lightOnImage;
	juce::Image lightOffImage;
	
};
