#ifndef GameObject_HPP
#define GameObject_HPP

#include <map>
#include <iostream>
#include "Managers.hpp"

class GameObject 
{
    private:
        std::map<std::string, Component*> components;
        
    public:
        //int x;
        //int y;
        ManagerController controller;

        template <class T>
        T* getComponent(T component)
        {
            T* newComponent = static_cast<T*> (components[typeid(T).name()]);
    
            return newComponent;
        };

        template <typename T>
        void addComponent(T component)
        {
            T* newComponent = new T;
            //newComponent->gameObject = this;

            if(typeid(T).name() == typeid(Renderer).name())
            {
                controller.renderManager.addRenderer(newComponent);
            }

            components[typeid(T).name()] = newComponent;
        }
    
        void removeComponent(std::string key)
        { 
            if(key == typeid(Renderer).name())
            {
                Renderer* component = static_cast<Renderer*> (components[key]);

                controller.renderManager.removeRenderer(component);
            }

            delete components[key];
            components.erase(key);
        }
};
 
#endif