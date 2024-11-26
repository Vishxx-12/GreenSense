# Three.js Website with Vite

This project sets up a basic Three.js scene and serves it using Vite, a fast development tool. It allows you to build interactive 3D graphics on the web.

## Prerequisites

- **Node.js**: Ensure you have Node.js installed. You can check your version by running:

  node -v


- **npm**: npm (Node Package Manager) comes with Node.js. Check if it's installed by running:

  npm -v


## Getting Started

### 1. Install Dependencies

In your project directory, run the following command to install all dependencies:


npm install


This will install Three.js and other dependencies defined in the `package.json`.

### 2. Start the Development Server

Once dependencies are installed, you can start the Vite development server by running:


npm run dev


This will start a local server at `http://localhost:3000` (or another port if specified). You should be able to open this URL in your browser and view the Three.js scene.

### 4. Build for Production

To build the project for production, use the following command:

npm run build 

## Project Structure

- `index.html`: The main HTML file where the Three.js scene will be rendered.
- `src/`: Contains all your JavaScript files, including the main script to create and render the Three.js scene (`main.js`).
- `vite.config.js`: Configuration file for Vite, where you can adjust development settings if needed.
- `package.json`: Defines project dependencies and scripts for building and running the project.
