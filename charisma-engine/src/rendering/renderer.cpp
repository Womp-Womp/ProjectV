#include "renderer.h"
#include <iostream>

Renderer::Renderer() {
    std::cout << "Renderer created" << std::endl;
}

Renderer::~Renderer() {
    std::cout << "Renderer destroyed" << std::endl;
}

void Renderer::initialize() {
    std::cout << "Renderer initialized" << std::endl;
}

void Renderer::render() {
    // Rendering logic
}
