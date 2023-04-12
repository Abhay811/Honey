#include "honey_pch.h"
#include "layer_stack.h"

namespace Honey {

	LayerStack_C::LayerStack_C()
	{
		_layer_insert = _layers.begin();
	}

	LayerStack_C::~LayerStack_C()
	{
		for (Layer_C* layer : _layers)
			delete layer;
	}

	void LayerStack_C::PushLayer(Layer_C* layer)
	{
		_layer_insert = _layers.emplace(_layer_insert, layer);
	}

	void LayerStack_C::PushOverlay(Layer_C* overlay)
	{
		_layers.emplace_back(overlay);
	}

	void LayerStack_C::PopLayer(Layer_C* layer)
	{
		auto it = std::find(_layers.begin(), _layers.end(), layer);
		if (it != _layers.end())
		{
			_layers.erase(it);
			_layer_insert--;
		}
	}

	void LayerStack_C::PopOverlay(Layer_C* overlay)
	{
		auto it = std::find(_layers.begin(), _layers.end(), overlay);
		if (it != _layers.end())
			_layers.erase(it);
	}
}