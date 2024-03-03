#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

template <typename T>
class Rectangle
{
    public:
        Rectangle(T gauche, T droite, T bas, T haut);
        void deplacer(T x, T y);
        bool estContenu(T x, T y) const;
        T hauteur() const;
        T longueur() const;
        T surface() const;
        T perimetre() const;

    private:
        T m_gauche;
        T m_droite;
        T m_bas;
        T m_haut;
};

// les définitions sont fortement conseillées d'être dans le header
template <typename T>
Rectangle<T>::Rectangle(T gauche, T droite, T bas, T haut)
    :m_gauche(gauche),
     m_droite(droite),
     m_bas(bas),
     m_haut(haut)
{}

template <typename T>
void Rectangle<T>::deplacer(T x, T y)
    {
        m_gauche += x;
        m_droite += x;
        m_bas += y;
        m_haut += y;
    }

template <typename T>
bool Rectangle<T>::estContenu(T x, T y) const
{
    return (x >= m_gauche) && (x <= m_droite) && (y >= m_bas) && (y <= m_haut);
}

template <typename T>
T Rectangle<T>::hauteur() const
{
    return m_haut - m_bas;
}

template <typename T>
T Rectangle<T>::longueur() const
{
    return m_droite - m_gauche;
}

template <typename T>
T Rectangle<T>::surface() const
{
    return hauteur() * longueur();
}

template <typename T>
T Rectangle<T>::perimetre() const
{
    return 2 * (hauteur() + longueur());
}

/*

Trois possibilités :
1 - définir les méthodes dans le Rectangle.hpp
        (celle conseillée. le seul défaut est le code bloat.)
2 - définir les méthodes dans un Rectangle.cpp et
    2a - #include Rectangle.cpp au début du main.cpp
 ou 2b - instancier en fin de Rectangle.cpp, les "template class Rectangle<int>; template class Rectangle<double>; ..."

https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor
https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file

*/

#endif