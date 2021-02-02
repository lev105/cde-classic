# What is this?

CDE Classic is a new project to port The Open Group's CDE release 2.1.30 to its original reference platforms.

# Why?

A number of UNIX vendors continue to ship the original CDE/Motif 1.x, but Motif 2.x offers a
vastly improved design and API for programmers who want to code native X11 applications.

# How does CDE Classic differ from the open source CDE project at https://sourceforge.net/p/cdesktopenv/?

Whereas the SourceForge project wants to modernize CDE and make it more compatible with the packaging
conventions of mainstream Linux distributions, CDE Classic is intended to focus almost solely upon
bugfixes and portability.

In particular:
- CDE Classic will continue to maintain code compatibility with ISO C90 and C++ 2.0 indefinitely.
Finding a compiler for these platforms that supports C99 or C++98 is often either expensive,
technically challenging or outright impossible on obsolete hardware.

- Compatibility shall be maintained with X11R6, SVID4, and POSIX 1990.

- Switching build systems from imake, the removal of legacy code, and unnecessary refactoring are not on the agenda.
