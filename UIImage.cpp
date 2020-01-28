#include "stdafx.h"
#include "UIImage.h"


UIImage::UIImage()
{
}


UIImage::~UIImage()
{
}

void UIImage::Awake()
{
	SetTexture(L"Source/uiimage.png", D3DXVECTOR2(150,100));
	texture.camera_on = false;
}

void UIImage::Update()
{
}
