export async function onRequest(context) {
  const url = new URL(context.request.url);

  // Serve static assets from the 'site' directory
  // context.env.ASSETS.fetch() fetches the file from the static assets
  let response = await context.env.ASSETS.fetch(context.request);

  // If the request results in a 404 (Not Found), serve index.html
  // This handles Single Page Application (SPA) routing if needed in the future
  if (response.status === 404) {
    return context.env.ASSETS.fetch(new URL('/index.html', context.request.url));
  }

  return response;
}
