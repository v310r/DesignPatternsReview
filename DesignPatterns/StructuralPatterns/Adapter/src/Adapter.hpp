#pragma once
#include <memory>
#include <vector>


struct Point
{
    int x, y;
};

struct Line
{
    Point start, end;
};

struct VectorObject
{
    virtual std::vector<Line>::iterator begin() = 0;
    virtual std::vector<Line>::iterator end() = 0;
};

struct VectorRectangle : VectorObject
{
    VectorRectangle(int x, int y, int width, int height)
    {
        lines.emplace_back(Line{ Point {x, y} , Point{x + width, y} });
        lines.emplace_back(Line{ Point {x + width, y} , Point{x + width, y + height} });
        lines.emplace_back(Line{ Point {x, y} , Point{x + width, y + height} });
        lines.emplace_back(Line{ Point {x, y + height} , Point{x + width, y + height} });
    }

    std::vector<Line>::iterator begin() override
    {
        return lines.begin();
    }

    std::vector<Line>::iterator end() override
    {
        return lines.end();
    }

private:
    std::vector<Line> lines;
};

struct LineToPointAdapter
{
    typedef std::vector<Point> Points;

    LineToPointAdapter(Line& line)
    {
        int left = std::min(line.start.x, line.end.x);
        int right = std::max(line.start.x, line.end.x);
        int top = std::min(line.start.y, line.end.y);
        int bottom = std::max(line.start.y, line.end.y);
        int dx = right - left;
        int dy = line.end.y - line.start.y;
        // only vertical or horizontal lines
        if (dx == 0)
        {
            // vertical
            for (int y = top; y <= bottom; ++y)
            {
                points.emplace_back(Point{ left,y });
            }
        }
        else if (dy == 0)
        {
            for (int x = left; x <= right; ++x)
            {
                points.emplace_back(Point{ x, top });
            }
        }
    }

    virtual Points::iterator begin()
    {
        return points.begin();
    }

    virtual Points::iterator end()
    {
        return points.end();
    }

private:

    Points points;
};



/*
        Adapter is a very simple concept: it allows you to adapt the interface you 
    have to the interface you need. The only real issue with adapters is that, in 
    the process of adaptation, you sometimes end up generating temporary 
    data so as to satisfy some other representation of data. And when this 
    happens, turn to caching: ensuring that new data is only generated when 
    necessary. Oh, and you’ll need to do a bit more work if you want to clean 
    up stale data when the cached objects have changed.
        Another concern that we haven’t really addressed is laziness: the 
    current adapter implementation performs the conversion as soon as it 
    is created. What if you only want the work to be done when the adapter 
    is actually used? This is rather easy to do and is left as an exercise for the 
    reader.
*/