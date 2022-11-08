//Academy
#include<iostream>
#include<string>
using namespace std;

#define delimiter "\n------------------------------------------\n"

#define HUMAN_TAKE_PARAMETERS	const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETER	last_name, first_name, age

class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	
	//				Constructors:
	Human(HUMAN_TAKE_PARAMETERS):
		last_name(last_name), first_name(first_name), age(age)
	{
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//				Methods:
	virtual void print()const
	{
		cout << last_name << " " << first_name << " " << age << " ���.\n";
	}
};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age() << " y.o.";
}

#define STUDENT_TAKE_PARAMETERS	const std::string& specialty, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS	specialty, group, rating, attendance

class Student :public Human
{
	std::string specialty;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_specialty()const
	{
		return specialty;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_specialty(const std::string& specialty)
	{
		this->specialty = specialty;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	//					Constructors:
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS):Human(HUMAN_GIVE_PARAMETER)
	{
		this->specialty = specialty;
		this->group = group;
		this->rating = rating;
		this->attendance = attendance;
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	//					Methods:
	void print()const
	{
		Human::print();
		cout << specialty << " " << group << " " << rating << " " << attendance << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const Student& obj)
{
	os << (Human&)obj << " ";
	return os << obj.get_specialty() << " " << obj.get_group() << " " << obj.get_rating() << " " << obj.get_attendance();
}

class Teacher :public Human
{
	std::string specialty;
	unsigned int experience;
public:
	const std::string& get_specialty()const
	{
		return specialty;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_specialty(const std::string& specialty)
	{
		this->specialty = specialty;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}

	//				Constructors:
	Teacher(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& specialty, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		set_specialty(specialty);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	//				Methods:
	void print()const
	{
		Human::print();
		cout << specialty << " " << experience << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const Teacher& obj)
{
	os << (Human&)obj;
	return os << obj.get_specialty() << " " << obj.get_experience() << " years";
}

class Undergrad:public Student
{
	std::string topic;
public:
	const std::string& get_topic()const
	{
		return topic;
	}
	void set_topic(const std::string& topic)
	{
		this->topic = topic;
	}
	//				Constructors:
	Undergrad(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& topic) :
		Student(HUMAN_GIVE_PARAMETER, STUDENT_GIVE_PARAMETERS)
	{
		set_topic(topic);
		cout << "GConstructor:\t" << this << endl;
	}
	~Undergrad()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	//				Methods:
	void print()const
	{
		Student::print();
		cout << "���� ���������� �������: " << topic << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const Undergrad& obj)
{
	return os << (Student&)obj << " " << obj.get_topic();
}

//#define INHERITANCE

void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE
	Human human("Montana", "Antoio", 25);
	human.print();
	cout << delimiter << endl;

	Student stud("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 90, 95);
	stud.print();
	cout << delimiter << endl;

	Teacher professor("White", "Walter", 50, "Chemistry", 20);
	professor.print();

	Undergrad hank("Schreder", "Hank", 40, "Criminalistic", "WW_220", 95, 80, "How to catch Heisenberg");
	hank.print();
#endif // INHERITANCE

	//Polymorphism (����������������) - ��� ����������� �������� ����� ���� �� ������� � ����������� �� �������������.
	//Ad-hoc polymorphism

	//Runtime polymorphism
	/*
		1. Pointers to base class - ��������� ������� ������ �������� ��������;
			Generalisation - ���������;
		2. Virtual methods;
	*/

	//Generalisation (UpCast - �������������� ����� ����� �����)
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 90, 95),
		new Teacher("White", "Walter", 50, "Chemistry", 20),
		new Undergrad("Schreder", "Hank", 40, "Criminalistic", "WW_220", 95, 80, "How to catch Heisenberg"),
		new Student("Vercetti", "Tomas", 30, "Criminalistic", "Vice", 98, 99),
		new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 15),
		new Teacher("Einstein", "Albert", 143, "Astronomy", 120)
	};

	//Specialisation - ��������� (DownCast - �������������� ������ ����)
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		//group[i]->print();
		//cout << *group[i] << endl;
		cout << typeid(*group[i]).name() << endl;
		if (typeid(*group[i]) == typeid(Student))cout << *dynamic_cast<Student*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Undergrad))cout << *dynamic_cast<Undergrad*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Teacher))cout << *dynamic_cast<Teacher*>(group[i]) << endl;
		//dynamic_cast<Derived*>(Base*);
		cout << delimiter << endl;
	}

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
}