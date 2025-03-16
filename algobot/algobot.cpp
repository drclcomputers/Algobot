#include <dpp/dpp.h>

using namespace std;

const string BOT_TOKEN = "Bot Token Here";

int main()
{
    /* Create algobot */
    dpp::cluster bot(BOT_TOKEN);

    bot.on_log(dpp::utility::cout_logger());

    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(dpp::slashcommand("ping", "Ping the bot!", bot.me.id));
            bot.global_command_create(dpp::slashcommand("proggim", "Link pentru programa de gimnaziu", bot.me.id));
            bot.global_command_create(dpp::slashcommand("proglic", "Link pentru programa de liceu", bot.me.id));
            bot.global_command_create(dpp::slashcommand("arhiva", "Arhiva educationala RoAlgo", bot.me.id));
            bot.global_command_create(dpp::slashcommand("infoOI", "Informatii despre Olimpiada de Informatica", bot.me.id));
            bot.global_command_create(dpp::slashcommand("psiho", "Psihologia concursurilor de informatica", bot.me.id));
        }
        });

    bot.on_slashcommand([](const dpp::slashcommand_t& event) -> dpp::task<void> {
        if (event.command.get_command_name() == "proggim") {
            co_await event.co_reply("https://edu.roalgo.ro/olimpiada/gimnaziu/");
        }
        else if (event.command.get_command_name() == "proglic") {
            co_await event.co_reply("https://edu.roalgo.ro/olimpiada/liceu/");
        }
        else if (event.command.get_command_name() == "ping") {
            co_await event.co_reply("Sunt aici!");
        }
        else if (event.command.get_command_name() == "arhiva") {
            co_await event.co_reply("https://edu.roalgo.ro/");
        }
        else if (event.command.get_command_name() == "infoOI") {
            co_await event.co_reply("https://edu.roalgo.ro/olimpiada/olympiad-info/");
        }
        else if (event.command.get_command_name() == "psiho") {
            co_await event.co_reply("https://www.algopedia.ro/wiki/index.php/Psihologia_concursurilor_de_informatic%C4%83");
        }
        co_return;
        });

    /* Start algobot */
    bot.start(dpp::st_wait);

    return 0;
}
