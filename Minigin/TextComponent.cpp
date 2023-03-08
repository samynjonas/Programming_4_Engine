#include <stdexcept>
#include <SDL_ttf.h>
#include "TextComponent.h"
#include "Font.h"

dae::TextComponent::TextComponent(std::weak_ptr<GameObject> pParent, const std::string& text, std::shared_ptr<Font> font)
	: Component(pParent)
	, m_NeedsUpdate{ false }
	, m_Text{ text }
	, m_Font(std::move(font))
{

}

dae::TextComponent::~TextComponent()
{

}

void dae::TextComponent::Update(float)
{
	if (m_NeedsUpdate)
	{
		const SDL_Color color = { 255,255,255 }; // only white text is supported now
		const auto surf = TTF_RenderText_Blended(m_Font->GetFont(), m_Text.c_str(), color);
		if (surf == nullptr)
		{
			throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
		}
		SDL_FreeSurface(surf);
		m_NeedsUpdate = false;
	}
}

void dae::TextComponent::SetText(const std::string& text)
{
	m_Text = text;
	m_NeedsUpdate = true;
}