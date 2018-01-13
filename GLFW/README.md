# ArchDevNotes
Personal reference guide to installing certain development tools on arch linux

installed: glfw-wayland.

Issue: glfw is a split package, I selected wayland as its more "modern". The issue comes in that this does not install the required definitions such as 'glfw/src/window.c' needed for development. Looking for solution such as cloning git and manually installing glfw headers.
