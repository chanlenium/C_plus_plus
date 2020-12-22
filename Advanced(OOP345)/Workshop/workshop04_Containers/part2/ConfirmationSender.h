#ifndef _CONFIRMATIONSENDER_H
#define _CONFIRMATIONSENDER_H
#include "Reservation.h"

namespace sdds
{
	const int MAX_SIZE = 20;

	class ConfirmationSender
	{
		const Reservation** confirmRes;
		size_t noOfReservation = 0u;
	public:
		ConfirmationSender();
		~ConfirmationSender();
		void setInit();
		void clearMemory();

		ConfirmationSender(const ConfirmationSender& src);
		ConfirmationSender& operator=(const ConfirmationSender& src);

		ConfirmationSender(ConfirmationSender&& src);
		ConfirmationSender&& operator=(ConfirmationSender&& src);

		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		void display(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& r);
	};
}
#endif



