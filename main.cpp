#include <iostream>
#include "vector"
#include "string"

using namespace std;

class People{
private:
string name;
int age;
public:
    People(){}
    People(string name,int age){
        this->name=name;
        this->age=age;
    }
    string getName(){
        return name;
    }

    void setName(const string &name) {
        People::name = name;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        People::age = age;
    }

    bool operator==(const People &rhs) const {
        return name == rhs.name &&
               age == rhs.age;
    }

    bool operator!=(const People &rhs) const {
        return !(rhs == *this);
    }
};

class Territories{
public:
    Territories() {
    }

    Territories(int size){
        this->size=size;
    }

    int getSize() const {
        return size;
    }

    void setSize(int s) {
        Territories::size = s;
    }

private:
    int size;
};

class Worker{
public:
    Worker(const People &people, float standing, float salary) : people(people), standing(standing), salary(salary) {}

    explicit Worker(const People &people) : people(people) {}

    const People &getPeople() const {
        return people;
    }

    void setPeople(const People &people) {
        Worker::people = people;
    }

    float getStanding() const {
        return standing;
    }

    void setStanding(float standing) {
        Worker::standing = standing;
    }

    float getSalary() const {
        return salary;
    }

    void setSalary(float salary) {
        Worker::salary = salary;
    }

    bool operator==(const Worker &rhs) const {
        return people == rhs.people &&
               standing == rhs.standing &&
               salary == rhs.salary;
    }

    bool operator!=(const Worker &rhs) const {
        return !(rhs == *this);
    }

private:
    People people;
    float standing;
    float salary;
};

class Population {
public:
    Population() {};

    Population(const vector<People> &population, const vector<Worker> &workers) : population(population),
                                                                                  workers(workers) {}

    void addPeople(People people) {
        population.push_back(people);
    }

    void addWorker(Worker worker) {
        workers.push_back(worker);
    }

    void delPeople(People &people) {
        population.erase(population.begin() + searchPeople(people));
    }

    void delWorker(Worker &worker) {
        workers.erase(workers.begin() + searchWorker(worker));
    }

    /*
    const vector<People> &getPopulation() const {
        return population;
    }

    const vector<Worker> &getWorkers() const {
        return workers;
    }
     */

private:
    vector<People> population;
    vector<Worker> workers;

    int searchPeople(const People &people) {
        int k = 0;
        for (const auto &i: population) {
            if (i == people) {
                return k;
            } else {
                k += 1;
            }
        }
    }

    int searchWorker(const Worker &worker) {
        int k = 0;
        for (const auto &i: workers) {
            if (i == worker) {
                return k;
            } else {
                k += 1;
            }
        }
    }
};

class State{
public:
    State(const Territories &territories, Population population) : territories(territories),
                                                                          population(std::move(population)) {}

     Territories &getTerritories(){
        return territories;
    }

    void setTerritories(const Territories &terr) {
        State::territories = terr;
    }

    Population getPopulation(){
        return population;
    }

    void setPopulation(const Population &popul) {
        State::population = popul;
    }
    
private:
    Territories territories;
    Population population;
};



int main() {
State state = State(Territories(),Population());
state.getPopulation().addPeople(People("Billy Bons",43));
state.getPopulation().addWorker(Worker(People("Billy Bons",43),2.4,3000.34));
}
