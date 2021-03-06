#include "GameObject.hpp"

GameObject::~GameObject()
{
    controller->animationManager.removeAnimation(this);
    controller->renderManager.removeRenderer(this);
    controller->physicsManager.removePhysics(this);
    controller->scriptManager.removeAllScriptsFromOneGameObject(this);

    int len = components.size();

    std::map<std::string, Component*>::iterator it = components.begin();

    for (int i = 0; i < len; i++) 
    {
        components.erase(it++);
    }
}