#pragma once
#include "../Core/live.hpp"

using namespace System;

namespace BrandBrigade
{

    public ref class ManagedObject
    {
    public:
        //ManagedObject() : m_Instance(new Live) {}
        ManagedObject() : m_Instance(NULL)
        {
            m_Instance = new Live(); // strange!!
        }

        virtual ~ManagedObject()
        {
            if (m_Instance != nullptr)
            {
                delete m_Instance;
            }
        }

        // delete this func?
        void Run()
        {
            m_Instance->Run();
        }

    protected:
    //private:
        Live* m_Instance;
    };
}