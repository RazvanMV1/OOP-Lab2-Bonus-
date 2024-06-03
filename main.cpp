#include<iostream>
#include <string>
using namespace std;

class Movie
{
    string name;
    int an;
    double score;
    int length;
public:
    void set_name(string name)
    {
        this->name = name;
    }

    string get_name()
    {
        return this->name;
    }

    void set_year(int x)
    {
        this->an = x;
    }

    int get_year()
    {
        return this->an;
    }

    void set_score(double x)
    {
        if(0<=x && x<=10)
            this->score = x;
    }

    double get_score()
    {
        return this->score;
    }

    void set_length(int x)
    {
        this->length = x;
    }

    int get_length()
    {
        return this->length;
    }

    int years_passed()
    {
        return 2024 - this->an;
    }
};

int movie_compare_name(Movie f1, Movie f2)
{
    if (f1.get_name() < f2.get_name()) return -1;
    else if (f1.get_name() < f2.get_name()) return 0;
    else return 1;
}

int movie_compare_length(Movie f1, Movie f2)
{
    if (f1.get_length() < f2.get_length()) return -1;
    else if (f1.get_length() < f2.get_length()) return 0;
    else return 1;
}

int movie_compare_score(Movie f1, Movie f2)
{
    if (f1.get_score() < f2.get_score()) return -1;
    else if (f1.get_score() < f2.get_score()) return 0;
    else return 1;
}

int movie_compare_passed_years(Movie f1, Movie f2)
{
    if (f1.years_passed() < f2.years_passed()) return -1;
    else if (f1.years_passed() < f2.years_passed()) return 0;
    else return 1;
}

int movie_compare_year(Movie f1, Movie f2)
{
    if (f1.get_year() < f2.get_year()) return -1;
    else if (f1.get_year() < f2.get_year()) return 0;
    else return 1;
}

class MovieSeries
{
    int count;
    Movie* baza[16];

public:
    void init()
    {
        count = 0;
    }

    void add(Movie* film)
    {
        count++;
        baza[count] = film;
    }

    void print()
    {
        for (int i = 1;i <= count;i++)
            cout << baza[i]->get_name() << " : " << baza[i]->get_length() << " : " << baza[i]->get_score() << endl;
    }

    void sort()
    {
        for (int i = 1;i < count;i++)
        {
            for (int j = i + 1;j <= count;j++)
            {
                if (baza[i]->years_passed() > baza[j]->years_passed())
                {
                    Movie* aux = baza[i];
                    baza[i] = baza[j];
                    baza[j] = aux;

                }
            }
        }
    }
};


int main() {
    Movie ep5;
    ep5.set_name("Star Wars: Episode V - The Empire Strikes Back");
    ep5.set_score(8.7);
    ep5.set_year(1980);
    ep5.set_length(124);

    Movie ep4;
    ep4.set_name("Star Wars: Episode IV - A New Hope");
    ep4.set_score(8.6);
    ep4.set_year(1977);
    ep4.set_length(121);

    Movie ep6;
    ep6.set_name("Star Wars: Episode VI - Return of the Jedi");
    ep6.set_score(8.3);
    ep6.set_year(1983);
    ep6.set_length(131);

    printf(
        R"(
ep4, ep5 comparisons:
name        : %d
year        : %d
score       : %d
length      : %d
passed years: %d
)",
movie_compare_name(ep4, ep5),
movie_compare_year(ep4, ep5),
movie_compare_score(ep4, ep5),
movie_compare_length(ep4, ep5),
movie_compare_passed_years(ep4, ep5));

    MovieSeries series;
    series.init();
    series.add(&ep5);
    series.add(&ep4);
    series.add(&ep6);

    series.sort();
    series.print();
}
