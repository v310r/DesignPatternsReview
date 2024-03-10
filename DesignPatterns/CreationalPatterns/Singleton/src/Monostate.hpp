#pragma once

// Monostate is a variation on the Singleton pattern. It is a class that behaves
// like a singleton while appearing as an ordinary class

class Printer
{
public:

	int getId() const { return id; }

	void setId(int value) { id = value; }

private:

	static int id;
};

int Printer::id;
