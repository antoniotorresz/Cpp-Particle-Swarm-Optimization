#include <iostream>
#include <random>
#include<fstream>
#include<string>
#include <sstream>
#include "testFunctions.h"
#include "Libraries/matplotlibcpp.h"

namespace plt = matplotlibcpp;
namespace funct = TestFunctions;
using namespace std;

class Particle {
private:
    vector<float> position;
    vector<float> velocity;
    vector<float> bestPosition;
    float fitness, bestFitness; //El valor que arroja tu funcion de prueba
public:
    int id;

    Particle() {};

    ~Particle() {};

    Particle(int _id) { id = _id; }

    string toString() {
        stringstream ss;
        ss << id << "\t"
           << fitness << "\t"
           << bestFitness << "\t";
        ss << "(";
        for (int i = 0; i < position.size(); i++)
            ss << position.at(i) << ",";
        ss << ")";
        ss << "\t(";

        for (int i = 0; i < bestPosition.size(); i++)
            ss << bestPosition.at(i) << ",";
        ss << ")";
        ss << "\t(";

        for (int i = 0; i < velocity.size(); i++)
            ss << velocity.at(i) << ",";
        ss << ")";

        return ss.str();

    }

    //Getters
    vector<float> getPosition() { return position; }

    vector<float> getVelocity() { return velocity; }

    vector<float> getBestPosition() { return bestPosition; }

    float getFitness() { return fitness; }


    //setter
    void setFitness(float _fitness) { fitness = _fitness; }

    void setBestFitness(float _bestFitness) { bestFitness = _bestFitness; }

    void setPosition(vector<float> m_position) {
        copy(m_position.begin(), m_position.end(), back_inserter(position));
    }

    void setBestPosition(vector<float> m_bestPosition) {
        copy(m_bestPosition.begin(), m_bestPosition.end(), back_inserter(bestPosition));
    }

    void setVelocity(vector<float> m_Velocity) {
        copy(m_Velocity.begin(), m_Velocity.end(), back_inserter(velocity));
    }
};

void plotData(vector<Particle> currentPopulation, string flag) {
    vector<float> x, y;
    for (Particle p : currentPopulation) {
        x.push_back(p.getPosition().at(0));
        y.push_back(p.getPosition().at(1));
    }
    const string format = "o";
    plt::plot(x, y, format);
    plt::title(flag);
    plt::show();
}

int main() {
    // Probando la funcion esfera
    vector<Particle> population;
    Particle temp;
    float x, y, f;
    vector<float> posTemp;
    cout << "ID\tFitness\tBest Fitness\tPosition\tBest Position\tVelocity" << endl;
    for (int i = 1; i <= 100; i++) {
        temp = Particle(i);
        x = funct::randGen(-10, 10);
        y = funct::randGen(-10, 10);

        posTemp.push_back(x);
        posTemp.push_back(y);
        f = funct::sphereFun(x, y);

        temp.setFitness(f);
        temp.setBestFitness(f);
        temp.setPosition(posTemp);
        temp.setBestPosition(posTemp);
        temp.setVelocity(posTemp);
        population.push_back(temp);

        posTemp.clear();
        cout << temp.toString() << endl;

    }

    //Guardando en txt
    ofstream ofs;
    ofs.open("bitacora.txt", iostream::app);

    for (int i = 0; i < 3; i++) {
        ofs << population.at(i).toString() + "\n";
    }

    for (int i = population.size() - 3; i < population.size(); i++) {
        ofs << population.at(i).toString() + "\n";
    }

    plotData(population, "Initial population");

    return 0;
}