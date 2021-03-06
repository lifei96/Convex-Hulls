//
// Created by Fei Li on 2018/5/26.
//

#include "AHall.h"
#include <string>

AHall::AHall(std::vector<Point> &dataset) : dataset(dataset) {}

std::vector<Point> AHall::aHall(bool parallel) {
    sort(dataset.begin(), dataset.end(), AHall::xOrder());
    getPoles();
    if (parallel) {
        #pragma omp sections
        {
            { getld(); }
            #pragma omp section
            { getrd(); }
            #pragma omp section
            { getlu(); }
            #pragma omp section
            { getru(); }
        }
    } else {
        getld();
        getrd();
        getlu();
        getru();
    }
    getACH();
    getCH();
    return CH;
}

void AHall::getPoles() {
    l = 0;
    r = (int) dataset.size() - 1;
    u = 0;
    d = 0;
    for (int i = 1; i < dataset.size(); i++) {
        double pY = dataset[i].getY();
        if (pY > dataset[u].getY()) u = i;
        if (pY < dataset[d].getY()) d = i;
    }
}

void AHall::getld() {
    double minY = dataset[l].getY();
    ld.push_back(l);
    for (int i = l + 1; i <= d; i++) {
        if (dataset[i].getY() <= minY) {
            minY = dataset[i].getY();
            ld.push_back(i);
        }
    }
}

void AHall::getrd() {
    double minY = dataset[r].getY();
    rd.push_back(r);
    for (int i = r - 1; i >= d; i--) {
        if (dataset[i].getY() <= minY) {
            minY = dataset[i].getY();
            rd.push_back(i);
        }
    }
}

void AHall::getlu() {
    double maxY = dataset[l].getY();
    lu.push_back(l);
    for (int i = l + 1; i <= u; i++) {
        if (dataset[i].getY() >= maxY) {
            maxY = dataset[i].getY();
            lu.push_back(i);
        }
    }
}

void AHall::getru() {
    double maxY = dataset[r].getY();
    ru.push_back(r);
    for (int i = r - 1; i >= u; i--) {
        if (dataset[i].getY() >= maxY) {
            maxY = dataset[i].getY();
            ru.push_back(i);
        }
    }
}

void AHall::getACH() {
    ACH.insert(ACH.end(), ld.begin(), ld.end() - 1);
    std::reverse(rd.begin(), rd.end());
    ACH.insert(ACH.end(), rd.begin(), rd.end() - 1);
    ACH.insert(ACH.end(), ru.begin(), ru.end() - 1);
    std::reverse(lu.begin(), lu.end());
    ACH.insert(ACH.end(), lu.begin(), lu.end() - 1);
}

void AHall::getCH() {
    int last = 0, m = (int) ACH.size();
    for (int i = 0; i < m; i++) {
        Point A = dataset[ACH[last % m]];
        Point B = dataset[ACH[(i + 1) % m]];
        Point C = dataset[ACH[(i + 2) % m]];
        double dx = B.getX() - A.getX();
        double dy = B.getY() - A.getY();
        double Dx = C.getX() - A.getX();
        double Dy = C.getY() - A.getY();
        if (dx * Dy - dy * Dx > 0) {
            last = i + 1;
            CH.push_back(dataset[ACH[(i + 1) % m]]);
        }
    }
}

std::string AHall::print() {
    std::string output = "";
    output += "ld\n";
    for (auto i = ld.begin(); i != ld.end(); i++) {
        output += std::to_string(dataset[*i].getX()) + " " +
                  std::to_string(dataset[*i].getY()) + "\n";
    }
    output += "\nrd\n";
    for (auto i = rd.begin(); i != rd.end(); i++) {
        output += std::to_string(dataset[*i].getX()) + " " +
                  std::to_string(dataset[*i].getY()) + "\n";
    }
    output += "\nlu\n";
    for (auto i = lu.begin(); i != lu.end(); i++) {
        output += std::to_string(dataset[*i].getX()) + " " +
                  std::to_string(dataset[*i].getY()) + "\n";
    }
    output += "\nru\n";
    for (auto i = ru.begin(); i != ru.end(); i++) {
        output += std::to_string(dataset[*i].getX()) + " " +
                  std::to_string(dataset[*i].getY()) + "\n";
    }
    output += "\nACH\n";
    for (auto i = ACH.begin(); i != ACH.end(); i++) {
        output += std::to_string(dataset[*i].getX()) + " " +
                  std::to_string(dataset[*i].getY()) + "\n";
    }
    output += "\nCH\n";
    for (auto i = CH.begin(); i != CH.end(); i++) {
        output += std::to_string((*i).getX()) + " " +
                  std::to_string((*i).getY()) + "\n";
    }
    return output;
}