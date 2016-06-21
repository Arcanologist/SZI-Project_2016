#include <QString>


/* Funkcja decision zwraca do jakiego pola jedziemy następnego.
Oznaczenia:
- "B" jest polem na "lewo" od naszego (następne zgodnie z ruchemwskazówek zegara)
- "C" jest polem na "prawo" od naszego (następne przeciwnie z ruchemwskazówek zegara)
- "D" jest polem na naprzeciwko od naszego.
Przykładowo:
(startujemy z A)
_____________
|     |     |
|  A  |  B  |
|_____|____ |
|     |     |
|  C  |  D  |
|_____|_____|

Funkcja przyjmuje 6 stringów, po polei typy B C i D, oraz pokolei wilgotność B C i D.
Zwraca jeden z 4 stringów: "B", "C", "D" lub "error".
*/


QString decision (QString TypeB, QString TypeC, QString TypeD, QString HumidityB, QString HumidityC, QString HumidityD) {

QString decision = "error";

if(HumidityB == "CRIT"){
	if(HumidityD == "CRIT"){
		if(TypeD == "K"){
			if(TypeB == "K"){
				if(TypeC == "K") return decision="B";
				if(TypeC == "P"){
					if(HumidityC == "CRIT") return decision="C";
					if(HumidityC == "NORM") return decision="B";
				}
				if(TypeC == "S") return decision="B";
				if(TypeC == "Z"){
					if(HumidityC == "CRIT") return decision="C";
					if(HumidityC == "NORM") return decision="B";
				}
			}
			if(TypeB == "P") return decision="B";
			if(TypeB == "S"){
				if(HumidityC == "CRIT"){
					if(TypeC == "K") return decision="C";
					if(TypeC == "P") return decision="C";
					if(TypeC == "S") return decision="D";
					if(TypeC == "Z") return decision="C";
				}
				if(HumidityC == "NORM") return decision="D";
			}
			if(TypeB == "Z") return decision="B";
		}
		if(TypeD == "P"){
			if(TypeB == "K"){
				if(TypeC == "K") return decision="D";
				if(TypeC == "P"){
					if(HumidityC == "CRIT") return decision="C";
					if(HumidityC == "NORM") return decision="D";
				}
				if(TypeC == "S") return decision="D";
				if(TypeC == "Z"){
					if(HumidityC == "CRIT") return decision="C";
					if(HumidityC == "NORM") return decision="D";
				}
			}
			if(TypeB == "P"){
				if(TypeC == "K") return decision="B";
				if(TypeC == "P") return decision="B";
				if(TypeC == "S") return decision="B";
				if(TypeC == "Z"){
					if(HumidityC == "CRIT") return decision="C";
					if(HumidityC == "NORM") return decision="B";
				}
			}
			if(TypeB == "S"){
				if(TypeC == "K") return decision="D";
				if(TypeC == "P"){
					if(HumidityC == "CRIT") return decision="C";
					if(HumidityC == "NORM") return decision="D";
				}
				if(TypeC == "S") return decision="D";
				if(TypeC == "Z"){
					if(HumidityC == "CRIT") return decision="C";
					if(HumidityC == "NORM") return decision="D";
				}
			}
			if(TypeB == "Z") return decision="B";
		}
		if(TypeD == "S"){
			if(TypeB == "K") return decision="B";
			if(TypeB == "P") return decision="B";
			if(TypeB == "S"){
				if(HumidityC == "CRIT"){
					if(TypeC == "K") return decision="C";
					if(TypeC == "P") return decision="C";
					if(TypeC == "S") return decision="B";
					if(TypeC == "Z") return decision="C";
				}
				if(HumidityC == "NORM") return decision="B";
			}
			if(TypeB == "Z") return decision="B";
		}
		if(TypeD == "Z"){
			if(TypeB == "K") return decision="D";
			if(TypeB == "P") return decision="D";
			if(TypeB == "S") return decision="D";
			if(TypeB == "Z") return decision="B";
		}
	}
	if(HumidityD == "NORM"){
		if(HumidityC == "CRIT"){
			if(TypeB == "K"){
				if(TypeC == "K") return decision="B";
				if(TypeC == "P") return decision="C";
				if(TypeC == "S"){
					if(TypeD == "K") return decision="C";
					if(TypeD == "P") return decision="B";
					if(TypeD == "S") return decision="B";
					if(TypeD == "Z") return decision="B";
				}
				if(TypeC == "Z") return decision="C";
			}
			if(TypeB == "P"){
				if(TypeC == "K") return decision="B";
				if(TypeC == "P") return decision="B";
				if(TypeC == "S") return decision="B";
				if(TypeC == "Z") return decision="C";
			}
			if(TypeB == "S"){
				if(TypeC == "K") return decision="C";
				if(TypeC == "P") return decision="C";
				if(TypeC == "S") return decision="B";
				if(TypeC == "Z") return decision="C";
			}
			if(TypeB == "Z") return decision="B";
		}
		if(HumidityC == "NORM") return decision="B";
	}
}
if(HumidityB == "NORM"){
	if(HumidityC == "CRIT"){
		if(HumidityD == "CRIT"){
			if(TypeC == "K"){
				if(TypeD == "K") return decision="C";
				if(TypeD == "P") return decision="D";
				if(TypeD == "S") return decision="C";
				if(TypeD == "Z") return decision="D";
			}
			if(TypeC == "P"){
				if(TypeD == "K") return decision="C";
				if(TypeD == "P") return decision="C";
				if(TypeD == "S") return decision="C";
				if(TypeD == "Z") return decision="D";
			}
			if(TypeC == "S"){
				if(TypeD == "K") return decision="D";
				if(TypeD == "P") return decision="D";
				if(TypeD == "S") return decision="C";
				if(TypeD == "Z") return decision="D";
			}
			if(TypeC == "Z") return decision="C";
		}
		if(HumidityD == "NORM") return decision="C";
	}
	if(HumidityC == "NORM"){
		if(HumidityD == "CRIT") return decision="D";
		if(HumidityD == "NORM"){
			if(TypeB == "K"){
				if(TypeC == "K"){
					if(TypeD == "K") return decision="B";
					if(TypeD == "P") return decision="D";
					if(TypeD == "S") return decision="B";
					if(TypeD == "Z") return decision="D";
				}
				if(TypeC == "P") return decision="C";
				if(TypeC == "S"){
					if(TypeD == "K") return decision="B";
					if(TypeD == "P") return decision="D";
					if(TypeD == "S") return decision="C";
					if(TypeD == "Z") return decision="D";
				}
				if(TypeC == "Z") return decision="C";
			}
			if(TypeB == "P"){
				if(TypeD == "K") return decision="B";
				if(TypeD == "P") return decision="B";
				if(TypeD == "S") return decision="B";
				if(TypeD == "Z") return decision="D";
			}
			if(TypeB == "S"){
				if(TypeC == "K") return decision="C";
				if(TypeC == "P") return decision="C";
				if(TypeC == "S"){
					if(TypeD == "K") return decision="D";
					if(TypeD == "P") return decision="D";
					if(TypeD == "S") return decision="B";
					if(TypeD == "Z") return decision="D";
				}
				if(TypeC == "Z") return decision="C";
			}
			if(TypeB == "Z") return decision="B";
		}
	}
}
return decision;
}
