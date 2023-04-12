#pragma once

#include "Honey/core.h"
#include "layer.h"

namespace Honey {

	class HONEY_API LayerStack_C
	{
	public:
		LayerStack_C();
		~LayerStack_C();

		void PushLayer(Layer_C* layer);
		void PushOverlay(Layer_C* overlay);
		void PopLayer(Layer_C* layer);
		void PopOverlay(Layer_C* overlay);

		std::vector<Layer_C*>::iterator begin() { return _layers.begin(); }
		std::vector<Layer_C*>::iterator end() { return _layers.end(); }

	private:
		std::vector<Layer_C*> _layers;
		std::vector<Layer_C*>::iterator _layer_insert;
	};

}