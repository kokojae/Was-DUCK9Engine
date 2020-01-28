#include "stdafx.h"
#include "UIText.h"


UIText::UIText()
{
}


UIText::~UIText()
{
}

void UIText::Render()
{
	GrapicManager::TextUIRender(text.c_str(), position, scale);
}