#include <iostream>
using namespace std;
#include "arg_parser.h"
#include <QString>
#include <QStringList>
#include "../Engine/Filter.h"
#include "../Engine/CEngine.h"

int main(int argc, char *argv[])
{
	CEngine Engine;
	typedef pair<char, double> command;
	string sSourcePath, sResultPath, sErrors;
	vector< command > vCommands;

	const Arg_parser::Option Options[] =
	{
		{ 'x', "grayscale",   Arg_parser::no    },
		{ 'g', "gaussian",    Arg_parser::yes    },
		{ 's', "sobel",  Arg_parser::no },
		{ 'a', "gray-world",  Arg_parser::no },
		{ 'c', "autocontrast",  Arg_parser::no },
		{ 'l', "autolevels",  Arg_parser::no },
		{ 'r', "rotate",  Arg_parser::yes },
		{ 'z', "resize",  Arg_parser::yes },
	/*	{ 'k', "custom",  Arg_parser::yes },
		{ 'w', "waves",  Arg_parser::yes }, */
		{ 'm', "median",  Arg_parser::no },
		{ 'd', "myfilt",  Arg_parser::no },

	};

	const Arg_parser ArgParser( argc, argv, Options );
	if( ArgParser.error().size())
	{
		cerr<<"Command line error: "<<ArgParser.error()<<endl;
		return -1;
	}

	for (uint k = 0; k < ArgParser.arguments(); ++k)
	{
		int iCode = ArgParser.code(k);

		if (iCode != 0)
		{
			vCommands.push_back(command((char)iCode, atof(ArgParser.argument(k).data())));
		}
		else
		{
			if (sSourcePath.empty())
				sSourcePath = ArgParser.argument(k);
			else if (sResultPath.empty())
				sResultPath = ArgParser.argument(k);
			else
			{
				cerr<<"invalid unnamed command-line argument"<<endl;
				return -1;
			}
		}
	}

	if (sSourcePath.empty())
		sErrors += "\n* Source path was not specified.";
	if (sResultPath.empty())
		sErrors += "\n* Result path was not specified.";
	if (!Engine.load(sSourcePath))
		sErrors += "\n* Can't load source image";

	if (!sErrors.empty())
	{
		cerr<<"Some errors were found:";
		cerr<<sErrors<<endl;
		return -1;
	}

	for (uint i = 0; i < vCommands.size(); ++i)
	{
		switch (vCommands[i].first)
		{
		case 'x':
			Engine.toGrayscale(false);
			break;
		case 'g':
			cout<<"Gaussian; sigma = "<<vCommands[i].second<<endl;
			Engine.setSigma(vCommands[i].second);
			Engine.toGauss(false);
			break;
		case 's':
			Engine.toSobel(false);
			break;
		case 'a':
			Engine.toGrayWorld(false);
			break;
		case 'c':
			Engine.toHistEq(false);
			break;
		case 'l':
			Engine.toStretchChan(false);
			break;
		case 'r':
			cout<<"Rotation; angle = "<<vCommands[i].second<<endl;
			int ang;
			ang = (int)vCommands[i].second;
			Engine.setAngle(ang);
			Engine.toRotate(false);
			break;
		case 'z':
			cout<<"Resize; proportion = "<<vCommands[i].second<<endl;
			Engine.setSigma(vCommands[i].second);
			Engine.toResize(false);
			break;
	/*	case 'k':
			cout<<"Linear; points = "<<ArgParser.argument(i).data()<<endl;
			{
				QString mline(ArgParser.argument(i).data());
				Filter newFil(mline);
				Engine.setFilter(newFil);
				Engine.toLinearFil(false);
			}
			break;
		case 'w':
			cout<<"Waves; parametrs = "<<ArgParser.argument(i).data()<<endl;
			{
				QString mline(ArgParser.argument(i).data());
				QStringList rows = mline.split(';');
				qreal ampX = rows[0].toDouble();
				qreal ampY = rows[1].toDouble();
				Engine.setAmplitude(ampX,ampY);
				qreal leng = rows[2].toDouble();
				Engine.setSigma(leng);
				Engine.toWaves(false);
			}
			break; */
		case 'm':
			Engine.toMedian(false);
			break;
		case 'd':
			Engine.toMyFiltr(false);
			break;

		default:
			cout<<"Unknown option: "<<vCommands[i].first<<"; its argument: "<<vCommands[i].second<<endl;
			break;
		}
	}

	if (!Engine.save(sResultPath))
	{
		cerr<<"Can't save output file"<<endl;
		return -1;
	}

	return 0;
}


/*
#include <QtCore/QCoreApplication>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	return a.exec();
}
*/