#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

constexpr size_t numberOfPoints = 10;

/**
 * Classe représentant un point en 3D avec des coordonnées x, y et z.
 */
class Point3D {
private:
    float x, y, z;

public:
    /**
     * Constructeur par défaut. Initialise les coordonnées avec des valeurs aléatoires.
     */
    Point3D() {
        x = static_cast<float>(rand() % 101);
        y = static_cast<float>(rand() % 101);
        z = static_cast<float>(rand() % 101);
    }

    /**
     * Constructeur avec des coordonnées spécifiées.
     * @param newx Coordonnée x.
     * @param newy Coordonnée y.
     * @param newz Coordonnée z.
     */
    Point3D(const float &newx, const float &newy, const float &newz) : x(newx), y(newy), z(newz) {}

    /**
     * Définit de nouvelles coordonnées pour le point.
     * @param newx Nouvelle coordonnée x.
     * @param newy Nouvelle coordonnée y.
     * @param newz Nouvelle coordonnée z.
     */
    void setXYZ(const float &newx, const float &newy, const float &newz) {
        x = newx;
        y = newy;
        z = newz;
    }

    /**
     * Définit une nouvelle valeur pour la coordonnée x.
     * @param newx Nouvelle coordonnée x.
     */
    void setX(const float &newx) {
        x = newx;
    }

    /**
     * Définit une nouvelle valeur pour la coordonnée y.
     * @param newy Nouvelle coordonnée y.
     */
    void setY(const float &newy) {
        y = newy;
    }

    /**
     * Définit une nouvelle valeur pour la coordonnée z.
     * @param newz Nouvelle coordonnée z.
     */
    void setZ(const float &newz) {
        z = newz;
    }

    /**
     * Récupère la valeur de la coordonnée x.
     * @return La coordonnée x.
     */
    float getX() const {
        return x;
    }

    /**
     * Récupère la valeur de la coordonnée y.
     * @return La coordonnée y.
     */
    float getY() const {
        return y;
    }

    /**
     * Récupère la valeur de la coordonnée z.
     * @return La coordonnée z.
     */
    float getZ() const {
        return z;
    }

    /**
     * Affiche les coordonnées du point.
     */
    void print() const {
        std::cout << "Point3D(" << x << ", " << y << ", " << z << ")" << std::endl;
    }

    /**
     * Calcule la distance entre ce point et un autre point en 3D.
     * @param otherPoint3D L'autre point en 3D.
     * @return La distance entre les deux points.
     */
    float distanceTo(const Point3D &otherPoint3D) const {
        float dx = x - otherPoint3D.x;
        float dy = y - otherPoint3D.y;
        float dz = z - otherPoint3D.z;
        return std::sqrt(dx * dx + dy * dy + dz * dz);
    }
};

/**
 * Classe représentant une trajectoire composée de plusieurs points en 3D.
 */
class Trajectory {
private:
    Point3D points[numberOfPoints];

public:
    /**
     * Affiche les points de la trajectoire.
     */
    void print() const {
        for (size_t i = 0; i < numberOfPoints; ++i) {
            std::cout << "Point " << i + 1 << ": ";
            points[i].print();
        }
    }

    /**
     * Récupère un point de la trajectoire en fonction de son indice.
     * @param n Indice du point à récupérer.
     * @return Le point correspondant à l'indice.
     */
    Point3D& getPoint(const int &n) {
        if (n >= 0 && n < numberOfPoints) {
            return points[n];
        } else {
            std::cerr << "Indice de point invalide. Retour du premier point par défaut." << std::endl;
            return points[0];
        }
    }

    /**
     * Calcule la distance totale de la trajectoire en additionnant les distances entre les points consécutifs.
     * @return La distance totale de la trajectoire.
     */
    float getTotalDistance() const {
        float totalDistance = 0.0f;
        for (size_t i = 0; i < numberOfPoints - 1; ++i) {
            totalDistance += points[i].distanceTo(points[i + 1]);
        }
        return totalDistance;
    }
};

// Classe My_vector
typedef float my_type;

/**
 * Classe représentant un vecteur de type spécifié.
 */
class My_vector {
private:
    size_t size;
    my_type *tab;

public:
    /**
     * Constructeur par défaut. Initialise un vecteur vide.
     */
    My_vector() : size(0), tab(nullptr) {}

    /**
     * Constructeur avec la taille spécifiée pour le vecteur. Initialise les éléments à zéro.
     * @param size La taille du vecteur.
     */
    My_vector(const size_t &size) : size(size) {
        if (size > 1024 * 1024 * 1024 / sizeof(my_type)) {
            std::cerr << "Bouge + qu'1 GO " << std::endl;
            exit(EXIT_FAILURE);
        }

        tab = new my_type[size];
        for (size_t i = 0; i < size; ++i) {
            tab[i] = 0;
        }
    }

    /**
     * Constructeur de copie. Copie le contenu d'un autre vecteur.
     * @param other Le vecteur à copier.
     */
    My_vector(const My_vector &other) : size(other.size) {
        tab = new my_type[size];
        for (size_t i = 0; i < size; ++i) {
            tab[i] = other.tab[i];
        }
    }

    /**
     * Destructeur. Libère la mémoire allouée pour le vecteur.
     */
    ~My_vector() {
        delete[] tab;
    }

    /**
     * Récupère la taille du vecteur.
     * @return La taille du vecteur.
     */
    const size_t &get_size() const {
        return size;
    }

    /**
     * Définit la valeur d'un élément du vecteur à l'indice spécifié.
     * @param index Indice de l'élément.
     * @param val Nouvelle valeur de l'élément.
     */
    void set_an_element(const size_t &index, const my_type &val) {
        if (index >= size) {
            size_t new_size = (index + 1 > size * 2) ? index + 1 : size * 2;
            my_type *new_tab = new my_type[new_size];
            for (size_t i = 0; i < size; ++i) {
                new_tab[i] = tab[i];
            }

            for (size_t i = size; i < new_size; ++i) {
                new_tab[i] = 0;
            }

            size = new_size;
            delete[] tab;
            tab = new_tab;
        }

        tab[index] = val;
    }

    /**
     * Récupère la valeur d'un élément du vecteur à l'indice spécifié.
     * @param index Indice de l'élément à récupérer.
     * @return La valeur de l'élément.
     */
    const my_type &get_an_element(const size_t &index) const {
        if (index >= size) {
            std::cerr << "Erreur : t hors index." << std::endl;
            exit(EXIT_FAILURE);
        }

        return tab[index];
    }

    /**
     * Ajoute une nouvelle valeur à la fin du vecteur.
     * @param val Nouvelle valeur à ajouter.
     */
    void push(const my_type &val) {
        set_an_element(size, val);
    }
};

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    Trajectory trajectory;

    std::cout << "Trajectory Points:" << std::endl;
    trajectory.print();

    Point3D& point3 = trajectory.getPoint(2);
    std::cout << "Point 3 (via getPoint): ";
    point3.print();

    float totalDistance = trajectory.getTotalDistance();
    std::cout << "Total Distance of Trajectory: " << totalDistance << std::endl;

    // Exemples d'utilisation de My_vector
    My_vector myVec(5);
    myVec.set_an_element(2, 42.0f);
    std::cout << "Size of myVec: " << myVec.get_size() << std::endl;
    std::cout << "Element at index 2: " << myVec.get_an_element(2) << std::endl;
    myVec.push(99.9f);
    std::cout << "Size of myVec after push: " << myVec.get_size() << std::endl;

    return 0;
}
