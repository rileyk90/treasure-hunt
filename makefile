playGame: main.cpp Game.cpp Character.cpp Diver.cpp Space.cpp Surface.cpp MainDeck.cpp CaptainsQuarters.cpp GunDeck.cpp CrewQuarters.cpp Infirmary.cpp CargoHold.cpp Brig.cpp Dice.cpp Item.cpp menu.cpp inputValidation.cpp inputValInt.cpp
	g++ -g -std=c++0x main.cpp Game.cpp Character.cpp Diver.cpp Space.cpp Surface.cpp MainDeck.cpp CaptainsQuarters.cpp GunDeck.cpp CrewQuarters.cpp Infirmary.cpp CargoHold.cpp Brig.cpp Dice.cpp Item.cpp menu.cpp inputValidation.cpp inputValInt.cpp -o playGame

test:
	valgrind --leak-check=full --show-leak-kinds=all playGame

clean:
	rm playGame
