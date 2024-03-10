#pragma once

#include <vector>
#include <iterator>


struct Neuron;
struct NeuronLayer;

template <typename Self> 
struct SomeNeurons
{
    template <typename T> 
    void connect_to(T& other)
    {
        for (Neuron& from : *static_cast<Self*>(this))
        {
            for (Neuron& to : other)
            {
                from.out.emplace_back(&to);
                to.in.push_back(&from);
            }
        }
    }
};

struct Neuron : SomeNeurons<Neuron>
{
    std::vector<Neuron*> in, out;
    unsigned int id;

    Neuron()
    {
        in.resize(100);
        out.resize(100);
        static int id = 1;
        this->id = id++;
    }

    Neuron* begin() { return this; }
    Neuron* end() { return this + 1; }
};

struct NeuronLayer : SomeNeurons<NeuronLayer>
{
    using LayerValues = std::vector<Neuron*>;

    LayerValues values;


    NeuronLayer(int count)
    {
        while (count-- > 0)
        {
            values.emplace_back(new Neuron());
        }
    }

    Neuron* begin()
    { 
        return values.empty() ? nullptr : values[0];
    }

    Neuron* end()
    { 
        return values[values.size() - 1];
    }

};
