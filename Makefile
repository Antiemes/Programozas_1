TEX = pdflatex -interaction nonstopmode
BIB = bibtex
DOCKERIMAGE = antiemes/latex

TEXFILES = $(shell find -name "*.tex" | sed 's,.tex,,')
BIBFILE = references.bib
FIGURES = $(shell find *.eps *.png *.jpg)

#all: $(MAINDOCUMENT).tex $(MAINDOCUMENT).bbl $(FIGURES)
#all: $(MAINDOCUMENT).tex $(FIGURES)
#	$(TEX) $(MAINDOCUMENT)
#	$(TEX) $(MAINDOCUMENT)

all: $(TEXFILES)

$(TEXFILES): %: %.tex
	$(TEX) $<
	$(TEX) $<

spell::
	ispell *.tex

clean::
	rm -fv *.aux *.log *.bbl *.blg *.toc *.out *.lot *.lof *.loa *.nav *.snm ??_*.pdf template.pdf

#$(MAINDOCUMENT).bbl: $(MAINDOCUMENT).tex $(BIBFILE)
#	$(TEX) $(MAINDOCUMENT)
#	$(BIB) $(MAINDOCUMENT)

docker-all::
	docker run --rm -v ${PWD}:/project -w /project $(DOCKERIMAGE)  make all
