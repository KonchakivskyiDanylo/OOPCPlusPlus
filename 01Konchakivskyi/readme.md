# C++ OOP First Project - NaUKMA

This repository contains my first project for the C++ Object-Oriented Programming course at the National University of Kyiv-Mohyla Academy (NaUKMA).

## Task Description

1. Design and justify the most efficient class for balanced triangles (`Triangle`) based on its vertices as points on a plane (from the perspective of avoiding copying and creating unnecessary objects).

2. Define and implement classes for plane points (`Point`) - the vertices of the triangle - and triangle sides as segments (`Triangle::Segment`). Avoid copying segment endpoints. Suggest selectors and modifiers for vertices, and methods for constructing sides.

3. Enhance the triangle with the ability to store the bases of medians when their calculation is needed. Find the medians of the triangle as instances of the `Triangle::Segment` class.

## Implementation

This repository contains the implementation of a memory-efficient triangle class and related components, following object-oriented programming principles and best practices in C++. The implementation focuses on avoiding unnecessary copying of vertices and creating excess objects while providing a clean API for working with triangles and their medians.

## Project Structure

- `Triangle` class - efficient representation of triangles
- `Point` class - 2D point representation
- `Triangle::Segment` class - line segment implementation
- Median calculation utilities

## Current Evaluation: 9/10
