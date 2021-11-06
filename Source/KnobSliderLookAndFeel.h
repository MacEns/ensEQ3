/*
  ==============================================================================

    KnobSliderLookAndFeel.h
    Created: 2 Nov 2021 11:56:15am
    Author:  Mac Ens

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class KnobSliderLookAndFeel  : public juce::LookAndFeel_V4
{
public:
    KnobSliderLookAndFeel();
    ~KnobSliderLookAndFeel() override;
	
	void drawRotarySlider(juce::Graphics& g,
						  int x,
						  int y,
						  int width,
						  int height,
						  float sliderPos,
						  float rotaryStartAngle,
						  float rotaryEndAngle,
						  juce::Slider& slider) override;
	
	void drawLabel(juce::Graphics& g, juce::Label& label) override;

	void setLogSlider(bool isLogSlider);

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KnobSliderLookAndFeel)
	juce::Image knobImage;
	juce::ImageComponent knobImageComponent;
	bool isLogSlider;
};
