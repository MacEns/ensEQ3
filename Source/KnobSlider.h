/*
  ==============================================================================

    KnobSlider.h
    Created: 2 Nov 2021 11:55:51am
    Author:  Mac Ens

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "KnobSliderLookAndFeel.h"

//==============================================================================
/*
 RotarySliderWithLabels(juce::RangedAudioParameter& rap, const juce::String& unitSuffix) :
 juce::Slider(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag,
									 juce::Slider::TextEntryBoxPosition::NoTextBox),
 param(&rap),
 suffix(unitSuffix)
*/
struct KnobSlider : public juce::Slider
{
public:
    KnobSlider(juce::RangedAudioParameter& rap, const juce::String& unitSuffix, bool isLogSlider);
    ~KnobSlider() override;

	void mouseDown(const juce::MouseEvent& event) override;
	void mouseUp(const juce::MouseEvent& event) override;
	
//    void resized() override;
	
	struct LabelPos
	{
		float pos;
		juce::String label;
	};
	
	juce::Array<LabelPos> labels;
	
	void paint(juce::Graphics& g) override;
	juce::Rectangle<int> getSliderBounds() const;
	int getTextHeight() const { return 14; }
	juce::String getDisplayString() const;
	bool isLogSlider;

private:
	KnobSliderLookAndFeel knobSliderLookAndFeel;
	juce::Point<int> mousePosition;
	juce::RangedAudioParameter* param;
	juce::String suffix;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KnobSlider)
};
