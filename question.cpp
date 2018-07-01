#include "question.h"

question::question(){}

question::question(int id, int userId, string date, int score, string title, string body){
    _id = id;
    _userId = userId;
    _date = date;
    _score = score;
    _title = title;
    _body = body;
}

question::~question(){}

int question::getId()
{
    return _id;
}

void question::setId(int id)
{
    _id = id;
}

void question::setUser(int userId)
{
    _userId = userId;
}

int question::getUser()
{
    return _userId;
}

string question::getDate()
{
    return _date;
}

void question::setDate(string date)
{
    _date = date;
}

int question::getScore()
{
    return _score;
}

void question::setScore(int score)
{
    _score = score;
}

string question::getTitle()
{
    return _title;
}

void question::setTitle(string title)
{
    _title = title;
}

string question::getBody()
{
    return _body;
}

void question::setBody(string body)
{
    _body = body;
}
