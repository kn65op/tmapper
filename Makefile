#programy
LEX = flex
YACC = bison
CC = g++

#flagi

CCFLAGS_C = -c -g
CCFLAGS_L = `pkg-config --cflags --libs gtk+-2.0` -g
LEXFLAGS = 
YACCFLAGS = -d

#pliki pomocznicze *.o
O_FILES = skaner.o analiser.o KML.o node.o main.o parser.o Document.o Placemark.o Folder.o Name.o Style.o Description.o textnode.o boolnode.o Visibility.o Point.o LineString.o LinearRing.o Polygon.o Multigeometry.o StyleURL.o Coordinates.o OuterBoundaryIs.o InnerBoundaryIs.o IconStyle.o LabelStyle.o LineStyle.o PolyStyle.o Color.o Scale.o Heading.o Icon.o Hotspot.o Href.o Width.o Fill.o Outline.o numbernode.o MainWindow.o TreeWindow.o

#reguły

all: TMapper

skaner.cpp: skaner.l
	$(LEX) $(LEXFLAGS) -o skaner.cpp skaner.l

skaner.o: skaner.cpp parser.hpp
	$(CC) $(CCFLAGS_C) -o skaner.o skaner.cpp

parser.hpp: parser.cpp

parser.cpp: gramatyka_bison.y
	$(YACC) $(YACCFLAGS) -o parser.cpp gramatyka_bison.y

pareser.o: parser.cpp
	$(CC) $(CCFLAGS_C) -o parser.o parser.cpp

analiser.o: Analiser.cpp
	$(CC) $(CCFLAGS_C) -o analiser.o Analiser.cpp

KML.o: KML.cpp KML.h
	$(CC) $(CCFLAGS_C) -o KML.o KML.cpp

node.o: node.cpp node.h
	$(CC) $(CCFLAGS_C) -o node.o node.cpp

main.o: main.cpp
	$(CC) $(CCFLAGS_C) $(CCFLAGS_L) -o main.o main.cpp

Document.o: Document.cpp Document.h
	$(CC) $(CCFLAGS_C) -o Document.o Document.cpp

Placemark.o: Placemark.cpp Placemark.h
	$(CC) $(CCFLAGS_C) -o Placemark.o Placemark.cpp

Folder.o: Folder.cpp Folder.h
	$(CC) $(CCFLAGS_C) -o Folder.o Folder.cpp

Name.o: Name.cpp Name.h
	$(CC) $(CCFLAGS_C) -o Name.o Name.cpp
	
Style.o: Style.cpp Style.h
	$(CC) $(CCFLAGS_C) -o Style.o Style.cpp

Description.o: Description.cpp Description.h
	$(CC) $(CCFLAGS_C) -o Description.o Description.cpp

textnode.o: textnode.cpp textnode.h
	$(CC) $(CCFLAGS_C) -o textnode.o textnode.cpp

Visibility.o: Visibility.cpp Visibility.h
	$(CC) $(CCFLAGS_C) -o Visibility.o Visibility.cpp

boolnode.o: boolnode.cpp boolnode.h
	$(CC) $(CCFLAGS_C) -o boolnode.o boolnode.cpp

numbernode.o: numbernode.cpp numbernode.h
	$(CC) $(CCFLAGS_C) -o numbernode.o numbernode.cpp

Point.o: Point.cpp Point.h
	$(CC) $(CCFLAGS_C) -o Point.o Point.cpp

LineString.o: LineString.cpp LineString.h
	$(CC) $(CCFLAGS_C) -o LineString.o LineString.cpp

LinearRing.o: LinearRing.cpp LinearRing.h
	$(CC) $(CCFLAGS_C) -o LinearRing.o LinearRing.cpp

Polygon.o: Polygon.cpp Polygon.h
	$(CC) $(CCFLAGS_C) -o Polygon.o Polygon.cpp

Multigeometry.o: Multigeometry.cpp Multigeometry.h
	$(CC) $(CCFLAGS_C) -o Multigeometry.o Multigeometry.cpp

StyleURL.o: StyleURL.cpp StyleURL.h
	$(CC) $(CCFLAGS_C) -o StyleURL.o StyleURL.cpp

Coordinates.o: Coordinates.cpp Coordinates.h
	$(CC) $(CCFLAGS_C) -o Coordinates.o Coordinates.cpp

OuterBoundaryIs.o: OuterBoundaryIs.cpp OuterBoundaryIs.h
	$(CC) $(CCFLAGS_C) -o OuterBoundaryIs.o OuterBoundaryIs.cpp

InnerBoundaryIs.o: InnerBoundaryIs.cpp InnerBoundaryIs.h
	$(CC) $(CCFLAGS_C) -o InnerBoundaryIs.o InnerBoundaryIs.cpp

IconStyle.o: IconStyle.cpp IconStyle.h
	$(CC) $(CCFLAGS_C) -o IconStyle.o IconStyle.cpp

LabelStyle.o: LabelStyle.cpp LabelStyle.h
	$(CC) $(CCFLAGS_C) -o LabelStyle.o LabelStyle.cpp

LineStyle.o: LineStyle.cpp LineStyle.h
	$(CC) $(CCFLAGS_C) -o LineStyle.o LineStyle.cpp

PolyStyle.o: PolyStyle.cpp PolyStyle.h
	$(CC) $(CCFLAGS_C) -o PolyStyle.o PolyStyle.cpp

Color.o: Color.cpp Color.h
	$(CC) $(CCFLAGS_C) -o Color.o Color.cpp

Scale.o: Scale.cpp Scale.h
	$(CC) $(CCFLAGS_C) -o Scale.o Scale.cpp

Heading.o: Heading.cpp Heading.h
	$(CC) $(CCFLAGS_C) -o Heading.o Heading.cpp

Icon.o: Icon.cpp Icon.h
	$(CC) $(CCFLAGS_C) -o Icon.o Icon.cpp

Hotspot.o: Hotspot.cpp Hotspot.h
	$(CC) $(CCFLAGS_C) -o Hotspot.o Hotspot.cpp

Href.o: Href.cpp Href.h
	$(CC) $(CCFLAGS_C) -o Href.o Href.cpp

Width.o: Width.cpp Width.h
	$(CC) $(CCFLAGS_C) -o Width.o Width.cpp

Fill.o: Fill.cpp Fill.h
	$(CC) $(CCFLAGS_C) -o Fill.o Fill.cpp

Outline.o: Outline.cpp Outline.h
	$(CC) $(CCFLAGS_C) -o Outline.o Outline.cpp

MainWindow.o: MainWindow.cpp MainWindow.h
	$(CC) $(CCFLAGS_C) $(CCFLAGS_L) -o MainWindow.o MainWindow.cpp

TreeWindow.o: TreeWindow.cpp TreeWindow.h
	$(CC) $(CCFLAGS_C) $(CCFLAGS_L) -o TreeWindow.o TreeWindow.cpp

clean:
	rm skaner.cpp parser.cpp parser.hpp $(O_FILES)
	
TMapper: $(O_FILES)
	$(CC) $(CCFLAGS_L) -o TMapper $(O_FILES)	
