#include"CapaPresentacion.h"

void CapaPresentacion::iniciSessio()
{
	try
	{
		cout << "\033[2J\033[1;1H";
		string sobrenom, contrasenya;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "** Iniciar Sessio **\n";
		cout << "Sobrenom:";
		getline(cin, sobrenom);
		cout << "Contrasenya:";
		getline(cin, contrasenya);
		cout << "\n";
		TxIniciSessio tx1 = TxIniciSessio(sobrenom, contrasenya);
		tx1.executar();
	}
	catch (string err)
	{
		cout << "\033[2J\033[1;1H";
		std::cerr << err << std::endl;
		throw;
	}

}

void CapaPresentacion::registrarUsuari()
{
	try
	{
		cout << "\033[2J\033[1;1H";
		string nom, sobrenom, contrasenya, correu_electronic, dataDeNaixament;
		cout << "** Registrar usuari **\n";
		cout << "Omplir la informacio que es demana...\n";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Nom usuari:";
		getline(cin, nom);
		cout << "Sobrenom:";
		getline(cin, sobrenom);
		cout << "Contrasenya:";
		getline(cin, contrasenya);
		cout << "Correu electronic:";
		getline(cin, correu_electronic);
		cout << "Data Naixament(DD-MM-AAAA):";
		getline(cin, dataDeNaixament);
		TxRegistraUsuari tx1 = TxRegistraUsuari(nom, sobrenom, contrasenya, correu_electronic, dataDeNaixament);
		tx1.executar();
		Videoconsola& videoconsola = Videoconsola::getInstance();
		videoconsola.refrescarUsuari(sobrenom);
		cout << "\033[2J\033[1;1H";
		cout << "Nou usuari registrat correctament! Pulsa Enter o qualsevol tecla per accedir al Menu";

	}
	catch (string err)
	{
		cout << "\033[2J\033[1;1H";
		std::cerr << err << std::endl;
		throw;
	}
}

void CapaPresentacion::consultaUsuari() {
	try {
		cout << "\033[2J\033[1;1H";
		TxConsultaUsuari tx1 = TxConsultaUsuari();
		tx1.executar();
		vector<string> infoU = tx1.obteResultat();
		cout << "** Consulta Usuari **\n";
		cout << "Nom complet: " << infoU[0] << "\n";
		cout << "Sobrenom: " << infoU[1] << "\n";
		cout << "Correu electronic: " << infoU[2] << "\n";
		cout << "Data naixement: " << infoU[3] << "\n\n";

		TxInfoCompres tx2 = TxInfoCompres();
		tx2.executar();
		vector<float> infoC = tx2.obteResultat();
		cout << infoC[0] << " videojocs comprats." << "\n";
		cout << infoC[1] << " paquets comprats." << "\n";
		cout << infoC[2] << " euros gastats en total." << "\n";
	}
	catch (string err) {
		cout << "\033[2J\033[1;1H";
		std::cerr << err << std::endl;
		throw;
	}
}

void CapaPresentacion::modificaUsuari()
{
	try
	{
		cout << "\033[2J\033[1;1H";
		vector<string> infou;
		CtrlModificaUsuari tx1 = CtrlModificaUsuari();
		infou = tx1.consultaUsuari();
		cout << "** Modificar usuari **\n";
		string nomU, sobrenomU, correU, neixU;
		nomU = infou[0];
		cout << "Nom complet: " << nomU << "\n";
		sobrenomU = infou[1];
		cout << "Sobrenom: " << sobrenomU << "\n";
		correU = infou[2];
		cout << "Correu_electronic: " << correU << "\n";
		neixU = infou[3];
		cout << "DataDeNaixament: " << neixU << "\n";
		cout << "Pulsa ENTER o qualsevol tecla per continuar";
		_getch();
		cout << "\033[2J\033[1;1H";
		cout << "Omplir la informacio que es vol modificar...*\n";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		string nomU2, contraU2, correU2, neixU2;
		cout << "Nom complet:";
		getline(cin, nomU2);
		cout << "Contrasenya: ";
		getline(cin, contraU2);
		cout << "Correu_electronic: ";
		getline(cin, correU2);
		cout << "DataDeNaixament: ";
		getline(cin, neixU2);
		tx1.modificarUsuari(nomU2, contraU2, correU2, neixU2);
		Videoconsola& videoconsola = Videoconsola::getInstance();
		videoconsola.refrescarUsuari(sobrenomU);
		cout << "Pulsa ENTER o qualsevol tecla per continuar";
		_getch();
		cout << "\033[2J\033[1;1H";
		infou = tx1.consultaUsuari();
		cout << "** Dades usuari modificades **\n";
		nomU2 = infou[0];
		cout << "Nom complet: " << nomU2 << "\n";
		sobrenomU = infou[1];
		cout << "Sobrenom: " << sobrenomU << "\n";
		correU2 = infou[2];
		cout << "Correu_electronic: " << correU2 << "\n";
		neixU2 = infou[3];
		cout << "DataDeNaixament: " << neixU2 << "\n";
	}
	catch (string err)
	{
		cout << "\033[2J\033[1;1H";
		std::cerr << err << std::endl;
		throw;
	}
}

void CapaPresentacion::esborraUsuari()
{
	try
	{
		cout << "\033[2J\033[1;1H";
		string contrasenya;
		cout << "** Esborrar usuari **\n";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Per confirmar l'esborrat,s'ha de entrar la contrasenya...\n";
		cout << "Contrasenya:";
		getline(cin, contrasenya);
		TxEsborraUsuari tx1 = TxEsborraUsuari(contrasenya);
		tx1.executar();
		cout << "\033[2J\033[1;1H";
		cout << "Usuari esborrat correctament! Pulsa Enter o qualsevol tecla per accedir al Menu";

	}
	catch (string err)
	{
		cout << "\033[2J\033[1;1H";
		std::cerr << err << std::endl;
		throw;
	}
}

void CapaPresentacion::comprarVideojoc()
{
	try
	{
		cout << "\033[2J\033[1;1H";
		string nomV;
		string res;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "** Comprar videojoc **\n";
		cout << "Nom videojoc: ";
		getline(cin, nomV);

		TxConsultaVideojoc tx1 = TxConsultaVideojoc();
		tx1.executar(nomV);
		vector<string> resultat = tx1.obteResultat();
		cout << "\033[2J\033[1;1H";
		cout << "Informacio videojoc...\n";
		cout << "Nom videojoc: " << resultat[0] << "\n";
		cout << "Descripcio: " << resultat[1] << "\n";
		cout << "Qualificacio edat: " << resultat[3] << "\n";
		cout << "Genere: " << resultat[2] << "\n";
		cout << "Data llançament: " << resultat[4] << "\n";
		cout << "Preu: " << resultat[5] << "€\n";
		cout << "Vols continuar amb la compra? (S/N): ";
		getline(cin, res);

		if (res == "S") {
			TxCompraVideojoc tx2 = TxCompraVideojoc();
			tx2.executar(nomV);
			cout << "\033[2J\033[1;1H";
			vector<string> result = tx2.obteResult();
			cout << "Compra registrada: " << result[0] << "\n";
			if (result.size() > 1) {
				cout << "Jocs relacionats:\n";
				for (int i = 1; i < result.size(); i++)
					cout << "- " << result[i] << " euros\n";
			}
		}
		else throw(string("L'usuari no confirma la compra"));
	}
	catch (string err)
	{
		cout << "\033[2J\033[1;1H";
		std::cerr << err << std::endl;
		throw;
	}

}

void CapaPresentacion::consultaVideojoc() {
	try {
		cout << "\033[2J\033[1;1H";
		string nomV;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "** Consulta videojoc **\n";
		cout << "Nom videojoc: ";
		getline(cin, nomV);

		TxConsultaVideojoc tx1 = TxConsultaVideojoc();
		tx1.executar(nomV);
		vector<string> resultat = tx1.obteResultat();
		vector<string> paquet = tx1.obtePaquets();
		cout << "\033[2J\033[1;1H";
		cout << "Informacio videojoc...\n";
		cout << "Nom videojoc: " << resultat[0] << "\n";
		cout << "Descripcio: " << resultat[1] << "\n";
		cout << "Qualificacio edat: " << resultat[3] << "\n";
		cout << "Genere: " << resultat[2] << "\n";
		cout << "Data llansament: " << resultat[4] << "\n";
		cout << "Preu: " << resultat[5] << " euros\n";
		if (resultat.size() > 6)cout << "Temps estinat: " << resultat[6] << "\n";

		if (paquet.size() != 0)cout << "Paquets on esta inclos: ";
		for (int i = 0; i < paquet.size(); i++) {
			if (paquet.size() - i > 1)
				cout << paquet[i] << ", ";
			else
				cout << paquet[i] << "\n";
		}
	}
	catch (string err) {
		cout << "\033[2J\033[1;1H";
		std::cerr << err << std::endl;
		throw;
	}
}

void CapaPresentacion::consultaVideojocs()
{
	try
	{
		cout << "\033[2J\033[1;1H";
		TxConsultaVideojocs tx1 = TxConsultaVideojocs();
		tx1.executar();
		vector<string> videojocs = tx1.obteVideojocs();

		cout << "** Consulta videojocs **\n";

		for (int i = 0; i < videojocs.size(); i++) {
			TxConsultaVideojoc tx2 = TxConsultaVideojoc();
			tx2.executar(videojocs[i]);
			vector<string> resultat = tx2.obteResultat();
			vector<string> paquet = tx2.obtePaquets();
			cout << resultat[0] << "; ";
			cout << resultat[1] << "; ";
			cout << resultat[5] << " euros; ";
			cout << resultat[3] << "; ";
			cout << resultat[2] << "; ";
			cout << resultat[4];
			if (resultat.size() > 6)cout << "; " << resultat[6];
			if (paquet.size() != 0)cout << " Paquets: ";
			else cout << "\n";
			for (int i = 0; i < paquet.size(); i++) {
				if (paquet.size() - i > 1)
					cout << paquet[i] << ", ";
				else
					cout << paquet[i] << "\n";
			}

		}
	}
	catch (string err)
	{
		cout << "\033[2J\033[1;1H";
		std::cerr << err << std::endl;
		throw;
	}
}

void CapaPresentacion::consultaVideojocsEdat()
{
	try
	{
		cout << "\033[2J\033[1;1H";
		int edatM;
		cout << "** Consulta videojocs per edat **\n";
		cout << "Edat maxima(anys): ";
		cin >> edatM;
		cout << "\033[2J\033[1;1H";
		TxConsultaVideojocsEdat tx1 = TxConsultaVideojocsEdat();
		tx1.executar(edatM);
		vector<string> videojocs = tx1.obteVideojocs();
		cout << "** Consulta videojocs fins a " << edatM << " anys**\n";
		for (int i = 0; i < videojocs.size(); i++) {
			TxConsultaVideojoc tx2 = TxConsultaVideojoc();
			tx2.executar(videojocs[i]);
			vector<string> resultat = tx2.obteResultat();
			vector<string> paquet = tx2.obtePaquets();
			cout << resultat[0] << "; ";
			cout << resultat[1] << "; ";
			cout << resultat[5] << " euros; ";
			cout << resultat[3] << "; ";
			cout << resultat[2] << "; ";
			cout << resultat[4];
			if (resultat.size() > 6)cout << "; " << resultat[6];
			if (paquet.size() != 0)cout << " Paquets: ";
			else cout << "\n";
			for (int i = 0; i < paquet.size(); i++) {
				if (paquet.size() - i > 1)
					cout << paquet[i] << ", ";
				else
					cout << paquet[i] << "\n";
			}

		}
	}
	catch (string err)
	{
		cout << "\033[2J\033[1;1H";
		std::cerr << err << std::endl;
		throw;
	}
}

void CapaPresentacion::consultaNovetatsVideojocs() {
	try
	{
		cout << "\033[2J\033[1;1H";
		string dataM;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "** Consulta novetats **\n";
		cout << "Data (DD/MM/AAA): ";
		getline(cin, dataM);
		if(dataM.empty()){
			time_t now = time(0);
   			tm *ltm = localtime(&now);
			dataM = to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year);
		}

		TxConsultaNovetatsVideojocs tx1 = TxConsultaNovetatsVideojocs();
		tx1.executar(dataM);
		vector<string> videojocs = tx1.obteVideojocs();
		cout << "\033[2J\033[1;1H";
		for (int i = 0; i < videojocs.size(); i++) {
			TxConsultaVideojoc tx2 = TxConsultaVideojoc();
			tx2.executar(videojocs[i]);
			vector<string> resultat = tx2.obteResultat();
			vector<string> paquet = tx2.obtePaquets();
			cout << resultat[0] << "; ";
			cout << resultat[1] << "; ";
			cout << resultat[5] << " euros; ";
			cout << resultat[3] << "; ";
			cout << resultat[2] << "; ";
			cout << resultat[4];
			if (resultat.size() > 6)cout << "; " << resultat[6];
			if (paquet.size() != 0)cout << " Paquets: ";
			else cout << "\n";
			for (int i = 0; i < paquet.size(); i++) {
				if (paquet.size() - i > 1)
					cout << paquet[i] << ", ";
				else
					cout << paquet[i] << "\n";
			}
		}		
	}
	catch (string err)
	{
		cout << "\033[2J\033[1;1H";
		std::cerr << err << std::endl;
		throw;
	}
}

void CapaPresentacion::consultarpaquet()
{

	try
	{
		cout << "\033[2J\033[1;1H";
		TxConsultaPaquet tx1 = TxConsultaPaquet();
		string nomP;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "** Consulta Paquet **\n";
		cout << "Nom del Paquet: ";
		getline(cin, nomP);
		cout << "\033[2J\033[1;1H";
		tx1.executar(nomP);
		float preuJocs =  tx1.obtepreuJocs();
		vector<string> paquetInfo = tx1.obteResultat();
		cout << "Nom paquet: "<< paquetInfo[0] << "\n";
		cout << "Descripcio: " << paquetInfo[1] << "\n";
		cout <<"Preu: "<< paquetInfo[2] << "(estalvi de " << preuJocs << "euros)\n";
		cout << "\n";
		vector<string> llista_videojocs = tx1.obteLlistavideojocs();
		cout << "Jocs inclosos: \n";
		for (int i = 0; i < llista_videojocs.size(); i++)
		{
			tx1.infoEC(llista_videojocs[i]);
			vector<string> info = tx1.obteInfoEC();
			cout << llista_videojocs[i] << "; ";
			cout << info[0] << "; ";
			cout << info[1] << "\n";	
		}


	}
	catch (string err)
	{
		cout << "\033[2J\033[1;1H";
		std::cerr << err << std::endl;
		throw;
	}
}

void CapaPresentacion::consultarpaquets()
{
	try
	{
		cout << "\033[2J\033[1;1H";
		TxConsultaPaquets tx1 = TxConsultaPaquets();
		tx1.executar();
		vector<string> llistat_paquets = tx1.obtePaquets();
		cout << "** Consulta paquets **\n";
		for (int i = 0; i < llistat_paquets.size(); i++)
		{
			TxConsultaPaquet tx2 = TxConsultaPaquet();
			tx2.executar(llistat_paquets[i]);
			float preuJocs = tx2.obtepreuJocs();
			tx2.infoEC(llistat_paquets[i]);
			vector<string> info = tx2.obteInfoEC();
			cout << llistat_paquets[i] << "; ";
			cout << info[0] << "; ";
			cout << info[1] << "(estalvi de " << preuJocs << "euros)\n";
		}
	}
	catch (string err)
	{
		cout << "\033[2J\033[1;1H";
		std::cerr << err << std::endl;
		throw;
	}
}

void CapaPresentacion::tancarSessio()
{
	try
	{
		cout << "\033[2J\033[1;1H";
		string tanca;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "** Tancar Sessio **\n";
		cout << "vols tancar la sessio?(Y/N)";
		getline(cin, tanca);
		if (tanca == "Y") {
			TxTancaSessio tx1 = TxTancaSessio();
			tx1.executar();
			cout << "\033[2J\033[1;1H";
			cout << "Sessio tancada correctament";
		}
		else
			throw(notancarsessio);
	}
	catch (string err)
	{
		cout << "\033[2J\033[1;1H";
		throw;
	}
}

void CapaPresentacion::consultarcompres()
{
	try
	{
		cout << "\033[2J\033[1;1H";
		TxInfoCompres tx2 = TxInfoCompres();
		tx2.executar();
		vector<string> compresU = tx2.obtecompres();
		cout << "** Consulta compres **\n";
		for (int i = 0; i < compresU.size(); i++)
		{
			TxInfoCompra tx3 = TxInfoCompra();
			tx3.executar(compresU[i]);
			vector<string> resultat = tx3.obteResultat();
			vector<string> videojocs_paquet = tx3.obteVideojocs_paquet();
			cout << resultat[0] << "; ";
			cout << resultat[1] << "; ";
			cout << resultat[2] << "; ";
			cout << resultat[3] << "\n";
			if (videojocs_paquet.size() != 0)
			{
				cout << "Videojocs:\n";
				for (int j = 0; j < videojocs_paquet.size(); j = j + 2)
				{
					cout << videojocs_paquet[j] << "; " << videojocs_paquet[j + 1] << "\n";
				}
			}
		}
		float totalEuros = tx2.obteResultat()[2];
		cout << "Total: " << totalEuros << "\n";
	}
	catch (string err)
	{
		cout << "\033[2J\033[1;1H";
		throw;
	}
}

void CapaPresentacion::comprarPaquet()
{
	try
	{
		cout << "\033[2J\033[1;1H";
		string nomP;
		string confiramcio;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "** Comprar Paquet **\n";
		cout << "Nom paquet: ";
		getline(cin, nomP);
		cout << nomP << "\n";
		TxConsultaPaquet tx2 = TxConsultaPaquet();
		tx2.executar(nomP);
		float estalvi = tx2.obtepreuJocs();
		cout << "Informacio paquet ...\n";
		vector<string> res = tx2.obteResultat();
		cout << "Nom paquet: " << res[0] << "\n";
		cout << "Descripcio: " << res[1] << "\n";
		cout << "Preu: " << res[2] << "(estalvi de " << estalvi << "euros)\n";
		cout << "\n";
		cout << "Jocs inclosos: \n";
		vector<string> llista_videojocs = tx2.obteLlistavideojocs();
		for (int i = 0; i < llista_videojocs.size(); i++)
		{
			tx2.infoEC(llista_videojocs[i]);
			vector<string> info = tx2.obteInfoEC();
			cout << llista_videojocs[i] << "; ";
			cout << info[0] << "; ";
			cout << info[1] << " euros\n";
		}
		cout << "Vols continuar amb la compra (S/N):";
		getline(cin, confiramcio);
		if (confiramcio == "S")
		{
			Videoconsola& videoconsola = Videoconsola::getInstance();
			PassarelaUsuari us = videoconsola.obteUsuari();
			string usuari = us.obteSobrenom();
			time_t now = time(0);
			tm* ltm = localtime(&now);
			string dataAvui = to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year);
			TxComprarPaquet tx1 = TxComprarPaquet(usuari,res[0],dataAvui,stof(res[2]));
			tx1.executar();
			cout << "Compra registrada: " << dataAvui << "\n";
		}
		else throw(nocomprar);
	}
	catch (string err)
	{
		cout << "\033[2J\033[1;1H";
		throw;
	}
}