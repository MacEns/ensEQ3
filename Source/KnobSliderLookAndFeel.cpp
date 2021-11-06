/*
  ==============================================================================

    KnobSliderLookAndFeel.cpp
    Created: 2 Nov 2021 11:56:15am
    Author:  Mac Ens

  ==============================================================================
*/

#include <JuceHeader.h>
#include "KnobSliderLookAndFeel.h"

//==============================================================================

KnobSliderLookAndFeel::KnobSliderLookAndFeel() : LookAndFeel_V4()
{
	// In your constructor, you should add any child components, and
	// initialise any special settings that your component needs.
	knobImage = juce::ImageCache::getFromMemory(BinaryData::Knob3b_png, BinaryData::Knob3b_pngSize);
	
}

KnobSliderLookAndFeel::~KnobSliderLookAndFeel()
{
}


void KnobSliderLookAndFeel::drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider)
{
	using namespace juce;
	
	if (knobImage.isValid())
	{
 
		knobImage = knobImage.rescaled(width * 0.75, width * 0.75);
		
		const float radius = knobImage.getWidth() * 0.5;
		auto bounds = Rectangle<float>(x, y, width, height);
		
		const float centerX = x + width * 0.5f;
		const float centerY = y + width * 0.5f;

		float sliderAngRad;

		if( isLogSlider)
		{
			float sliderPosLog = mapFromLog10(slider.getValue(), slider.getRange().getStart(), slider.getRange().getEnd());
			sliderAngRad = jmap(sliderPosLog, rotaryStartAngle, rotaryEndAngle);
			//printf("\nSlider is not log.");
		}
		else
		{
			float sliderPosProportional = jmap(slider.getValue(), slider.getRange().getStart(), slider.getRange().getEnd(), 0.0, 1.0);
			sliderAngRad = jmap(sliderPosProportional, rotaryStartAngle, rotaryEndAngle);
			//printf("\n%f Slider is log.", slider.getValue());
		}
		
		AffineTransform transform;
		transform = transform.translation(centerX - radius, centerY - radius);
		transform = transform.rotated(sliderAngRad, centerX, centerY);
		
		g.drawImageTransformed(knobImage, transform);
		
//		g.setColour(Colours::red);
//		g.drawRoundedRectangle(x, y, width, height, 10, 2);
	}
	else
	{
		static const float textPercent = 0.35f;
		Rectangle<float> text_bounds(1.0f + width * (1.0f - textPercent) / 2.0f, 0.5f * height, width * textPercent, 0.5f * height);

		g.setColour(Colours::red);

		g.drawFittedText(String("No Image"), text_bounds.getSmallestIntegerContainer(), Justification::horizontallyCentred | Justification::centred, 1);
	}
}

void KnobSliderLookAndFeel::drawLabel(juce::Graphics& g, juce::Label& label)
{
	using namespace juce;
	
	g.setColour(Colour(juce::uint8(255), 255, 255, 1.0f));
	g.fillRoundedRectangle(label.getLocalBounds().toFloat(), 3.0f);


	if (!label.isBeingEdited())
	{
		//auto alpha = label.isEnabled() ? 1.0f : 0.5f;
		const Font font(getLabelFont(label));

		g.setColour(Colour(uint8(0), 0, 0, 1.0f));
		g.setFont(font);

		auto textArea = getLabelBorderSize(label).subtractedFrom(label.getLocalBounds());

		g.drawFittedText(label.getText(), textArea, label.getJustificationType(),
			jmax(1, (int)(textArea.getHeight() / font.getHeight())),
			label.getMinimumHorizontalScale());

		g.setColour(Colour(uint8(255), 255, 255, 0.1f));
	}
	else if (label.isEnabled())
	{
		g.setColour(label.findColour(Label::outlineColourId));
	}

	//g.fillRoundedRectangle(label.getLocalBounds().toFloat(), 3.0f);
}// drawLabel

void KnobSliderLookAndFeel::setLogSlider(bool isLog)
{
	isLogSlider = isLog;
}
