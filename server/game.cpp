

class Game
{
    Player player_1; ///This class contain informations about the player tank where it is, what he'll do next etc.
    Player player_2;
    Player player_3;
    Player player_4;
    ///The player class can be used both by human player and AI.
    bool is_on = true;
    Area area;



    public:
        bool is_on()
        {
            return is_on;
        }
        bool what_to_do(Request player_request)
        {
            ///A lots of request types:
            //switch(type)
            //case
            ///Basicly, this switch calls Area or player functions which are changing game.
        }
        bool send(Player which_player)
        {
            ///Informations about game are send to the player.
        }
}
