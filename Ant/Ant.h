#pragma once

class Coordinates
{
public:
	Coordinates(unsigned int a, unsigned int b)
	{
		x = a;
		y = b;
	};
	~Coordinates()
	{
	};

    unsigned int x = 0;
    unsigned int y = 0;

    //Summ of the coordinates;
    int CSumm()
    {
        unsigned int x = this->x;
        unsigned int y = this->y;
        unsigned int SumX{0}, SumY{0}, n{0}, m{0};
        while (x != 0)
        {
            n = x % 10;
            SumX += n;
            x /= 10;
        }
        n = 0;
        while (y != 0)
        {
            n = y % 10;
            SumY += n;
            y /= 10;
        }
        return SumX+SumY;
    }

    Coordinates CUp(Coordinates coord)
    {
        Coordinates tmp(coord.x, ++coord.y);
        return tmp; 
    }

    Coordinates CDown(Coordinates coord)
    {
        Coordinates tmp(coord.x, --coord.y);
        return tmp;
    }

    Coordinates CRight(Coordinates coord)
    {
        Coordinates tmp(++coord.x, coord.y);
        return tmp;
    }
  
    Coordinates CLeft(Coordinates coord)
    {
        Coordinates tmp(--coord.x, coord.y);
        return tmp;
    }

    //overload
    bool operator == (const Coordinates& value)
    {
        return ((x == value.x) && (y == value.y));
    }

private:

};


