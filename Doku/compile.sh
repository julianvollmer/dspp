#!/bin/sh
pdflatex Museumstechnologien.tex && bibtex Museumstechnologien && pdflatex Museumstechnologien.tex && pdflatex Museumstechnologien.tex

rm *.aux
rm *.bbl
rm *.blg
rm *.lof
rm *.lot
rm *.out
rm *.log
rm *.run.xml

open Museumstechnologien.pdf &
