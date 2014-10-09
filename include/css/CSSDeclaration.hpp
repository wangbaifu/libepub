/*
Copyright (c) 2014, Richard Martin
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of Richard Martin nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL RICHARD MARTIN BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef CSS_DECLARATION_HEADER
#define CSS_DECLARATION_HEADER

#include <memory>

class CSSDeclaration;

#include "CSSSpecificity.hpp"
#include "CSSRule.hpp"
#include "CSSValue.hpp"

using std::shared_ptr;
using std::weak_ptr;

enum CSSPropertyType {

	ALIGN_CONTENT,
	ALIGN_ITEMS,
	ALIGN_SELF,
	ANIMATION,
	ANIMATION_DELAY,
	ANIMATION_DIRECTION,
	ANIMATION_DURATION,
	ANIMATION_FILL_MODE,
	ANIMATION_ITERATION_COUNT,
	ANIMATION_NAME,
	ANIMATION_PLAY_STATE,
	ANIMATION_TIMING_FUNCTION,
	BACKFACE_VISIBILITY,
	BACKGROUND,
	BACKGROUND_ATTACHMENT,
	BACKGROUND_CLIP,
	BACKGROUND_COLOR,
	BACKGROUND_IMAGE,
	BACKGROUND_ORIGIN,
	BACKGROUND_POSITION,
	BACKGROUND_REPEAT,
	BACKGROUND_SIZE,
	BORDER,
	BORDER_BOTTOM,
	BORDER_BOTTOM_COLOR,
	BORDER_BOTTOM_LEFT_RADIUS,
	BORDER_BOTTOM_RIGHT_RADIUS,
	BORDER_BOTTOM_STYLE,
	BORDER_BOTTOM_WIDTH,
	BORDER_COLLAPSE,
	BORDER_COLOR,
	BORDER_IMAGE,
	BORDER_IMAGE_OUTSET,
	BORDER_IMAGE_REPEAT,
	BORDER_IMAGE_SLICE,
	BORDER_IMAGE_SOURCE,
	BORDER_IMAGE_WIDTH,
	BORDER_LEFT,
	BORDER_LEFT_COLOR,
	BORDER_LEFT_STYLE,
	BORDER_LEFT_WIDTH,
	BORDER_RADIUS,
	BORDER_RIGHT,
	BORDER_RIGHT_COLOR,
	BORDER_RIGHT_STYLE,
	BORDER_RIGHT_WIDTH,
	BORDER_SPACING,
	BORDER_STYLE,
	BORDER_TOP,
	BORDER_TOP_COLOR,
	BORDER_TOP_LEFT_RADIUS,
	BORDER_TOP_RIGHT_RADIUS,
	BORDER_TOP_STYLE,
	BORDER_TOP_WIDTH,
	BORDER_WIDTH,
	BOTTOM,
	BOX_SHADOW,
	BOX_SIZING,
	CAPTION_SIDE,
	CLEAR,
	CLIP,
	COLOR,
	COLUMN_COUNT,
	COLUMN_FILL,
	COLUMN_GAP,
	COLUMN_RULE,
	COLUMN_RULE_COLOR,
	COLUMN_RULE_STYLE,
	COLUMN_RULE_WIDTH,
	COLUMN_SPAN,
	COLUMN_WIDTH,
	COLUMNS,
	CONTENT,
	COUNTER_INCREMENT,
	COUNTER_RESET,
	CURSOR,
	DIRECTION,
	DISPLAY,
	EMPTY_CELLS,
	FLEX,
	FLEX_BASI,
	FLEX_DIRECTION,
	FLEX_FLOW,
	FLEX_GROW,
	FLEX_SHRINK,
	FLEX_WRAP,
	FLOAT,
	FONT,
	FONT_FACE,
	FONT_FAMILY,
	FONT_SIZE,
	FONT_SIZE_ADJUST,
	FONT_STRETCH,
	FONT_STYLE,
	FONT_VARIANT,
	FONT_WEIGHT,
	HANGING_PUNCTUATION,
	HEIGHT,
	ICON,
	JUSTIFY_CONTENT,
	KEYFRAMES,
	LEFT,
	LETTER_SPACING,
	LINE_HEIGHT,
	LIST_STYLE,
	LIST_STYLE_IMAGE,
	LIST_STYLE_POSITION,
	LIST_STYLE_TYPE,
	MARGIN,
	MARGIN_BOTTOM,
	MARGIN_LEFT,
	MARGIN_RIGHT,
	MARGIN_TOP,
	MAX_HEIGHT,
	MAX_WIDTH,
	MEDIA,
	MIN_HEIGHT,
	MIN_WIDTH,
	NAV_DOWN,
	NAV_INDEX,
	NAV_LEFT,
	NAV_RIGHT,
	NAV_UP,
	OPACITY,
	ORDER,
	OUTLINE,
	OUTLINE_COLOR,
	OUTLINE_OFFSET,
	OUTLINE_STYLE,
	OUTLINE_WIDTH,
	CSS_OVERFLOW,
	CSS_OVERFLOW_X,
	CSS_OVERFLOW_Y,
	PADDING,
	PADDING_BOTTOM,
	PADDING_LEFT,
	PADDING_RIGHT,
	PADDING_TOP,
	PAGE_BREAK_AFTER,
	PAGE_BREAK_BEFORE,
	PAGE_BREAK_INSIDE,
	PERSPECTIVE,
	PERSPECTIVE_ORIGIN,
	POSITION,
	QUOTES,
	RESIZE,
	RIGHT,
	TAB_SIZE,
	TABLE_LAYOUT,
	TEXT_ALIGN,
	TEXT_ALIGN_LAST,
	TEXT_DECORATION,
	TEXT_DECORATION_COLOR,
	TEXT_DECORATION_LINE,
	TEXT_DECORATION_STYLE,
	TEXT_INDENT,
	TEXT_JUSTIFY,
	TEXT_OVERFLOW,
	TEXT_SHADOW,
	TEXT_TRANSFORM,
	TOP,
	TRANSFORM,
	TRANSFORM_ORIGIN,
	TRANSFORM_STYLE,
	TRANSITION,
	TRANSITION_DELAY,
	TRANSITION_DURATION,
	TRANSITION_PROPERTY,
	TRANSITION_TIMING_FUNCTION,
	UNICODE_BIDI,
	VERTICAL_ALIGN,
	VISIBILITY,
	WHITE_SPACE,
	WIDTH,
	WORD_BREAK,
	WORD_SPACING,
	WORD_WRAP,
	Z_INDEX

};

enum CSSValueType {
	CSS_VALUE_DEFAULT,
	CSS_VALUE_PX,
	CSS_VALUE_PT,
	CSS_VALUE_CM,
	CSS_VALUE_EM,
	CSS_VALUE_PERCENT
};

class CSSValue {

	public:
		double value;
		CSSValueType type;

		CSSValue();

		CSSValue(CSSValue const & cpy);
		CSSValue(CSSValue && mv) ;
		CSSValue & operator =(const CSSValue & cpy);
		CSSValue & operator =(CSSValue && mv) ;

		~CSSValue();

		inline bool operator==(const CSSValue & rhs) {
			if(value != rhs.value) {
				return false;
			}

			if(type != rhs.type) {
				return false;
			}

			return true;
		}

};

class CSSDeclaration {

	public:
		CSSPropertyType type;
		shared_ptr<CSSValueType> value;
		CSSSpecificity specificity;
		weak_ptr<CSSRule> parent;

		CSSDeclaration(CSSPropertyType _type, shared_ptr<CSSValueType> _value, CSSSpecificity _specificity, weak_ptr<CSSRule> _parent);

		CSSDeclaration(CSSDeclaration const & cpy);
		CSSDeclaration(CSSDeclaration && mv) ;
		CSSDeclaration & operator =(const CSSDeclaration & cpy);
		CSSDeclaration & operator =(CSSDeclaration && mv) ;

		~CSSDeclaration();

};

#endif