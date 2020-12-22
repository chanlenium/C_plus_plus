// Trailing Return - Enumeration within a class
# include <iostream>

class Ticket {
public:
	enum class TicketType{Adult, Child};
	void set(TicketType tt);
	TicketType get() const;
private:
	TicketType ticketType;
};

std::ostream& operator<<(std::ostream& os, const Ticket::TicketType& tt) {
	const char* label = nullptr;
	switch (tt) {
	case Ticket::TicketType::Adult:
		label = "Adult Ticket";
		break;
	case Ticket::TicketType::Child:
		label = "Child Ticket";
		break;
	default:
		label = "No Ticket";
	}
	os << label;
	return os;
}

void Ticket::set(TicketType tt) {
	ticketType = tt;
}

//// Trailing Return-Type Declaration
//// auto identifier(parameter-type-list) -> return-type
//auto Ticket::get() const -> TicketType { 
//	return ticketType; 
//}

// Without auto and trailing return-type,
// We would need to scope the return type
Ticket::TicketType Ticket::get() const {
	return ticketType;
}


int main() {
	Ticket a, b;
	a.set(Ticket::TicketType::Adult);
	b.set(Ticket::TicketType::Child);
	std::cout << a.get() << std::endl;
	std::cout << b.get() << std::endl;
}