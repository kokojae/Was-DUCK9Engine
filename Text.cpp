#include "stdafx.h"
#include "Text.h"


Text::Text()
{
}


Text::~Text()
{
}

void Text::Render()
{
	GrapicManager::TextRender(text.c_str() , position, scale);
}
